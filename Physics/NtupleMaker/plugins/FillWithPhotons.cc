#include "Physics/NtupleMaker/interface/NtupleMaker.h"

void NtupleMaker::FillWithPhotons(const edm::Event& iEvent)
{
    edm::Handle<edm::View<pat::Photon>> photons;
    edm::Handle<edm::View<pat::Photon>> calibratedPhotons;
    iEvent.getByToken(photons_token_, photons);
    if (egm_corrected_)
    {
        iEvent.getByToken(calibrated_photons_token_, calibratedPhotons);
        assert(photons->size() == calibratedPhotons->size());
    }

    edm::Handle<edm::ValueMap<bool> > loose_id_decisions;
    edm::Handle<edm::ValueMap<bool> > medium_id_decisions;
    edm::Handle<edm::ValueMap<bool> > tight_id_decisions;
    iEvent.getByToken(pho_cutbased_loose_id_token_, loose_id_decisions);
    iEvent.getByToken(pho_cutbased_medium_id_token_, medium_id_decisions);
    iEvent.getByToken(pho_cutbased_tight_id_token_, tight_id_decisions);

    edm::Handle<edm::ValueMap<float> > mvaValues;
    edm::Handle<edm::ValueMap<int> > mvaCategories;
    edm::Handle<edm::ValueMap<bool> > wp90_id_decisions;
    edm::Handle<edm::ValueMap<bool> > wp80_id_decisions;
    iEvent.getByToken(pho_mva_value_token_, mvaValues);
    iEvent.getByToken(pho_mva_category_token_, mvaCategories);
    iEvent.getByToken(pho_mva_wp90_id_token_, wp90_id_decisions);
    iEvent.getByToken(pho_mva_wp80_id_token_, wp80_id_decisions);

    edm::Handle<edm::ValueMap<float> > phoChargedIsolationMap;
    edm::Handle<edm::ValueMap<float> > phoNeutralHadronIsolationMap;
    edm::Handle<edm::ValueMap<float> > phoPhotonIsolationMap;
    iEvent.getByToken(pho_chiso_token_, phoChargedIsolationMap);
    iEvent.getByToken(pho_nhiso_token_, phoNeutralHadronIsolationMap);
    iEvent.getByToken(pho_phiso_token_, phoPhotonIsolationMap);

    edm::Handle<EcalRecHitCollection> ecalCalibHitEB_;
    iEvent.getByToken(ecalCalibHitEBToken_, ecalCalibHitEB_);

    event_.num_photons = photons->size();
    if (event_.num_photons == 0) return;
    
    for (unsigned i = 0; i< photons->size(); ++i) 
    {
        const auto photon = photons->ptrAt(i);

        /// GAIN & R9 ///
        const auto & hitsAndFractions = photon->superCluster()->hitsAndFractions();
        int g1 = 0;
        int g6 = 0;

        for (const auto & hnf : hitsAndFractions) 
        {
            auto crh = ecalCalibHitEB_->find(hnf.first);
            if (crh == ecalCalibHitEB_->end()) continue;
            g6 += crh->checkFlag(EcalRecHit::kHasSwitchToGain6);
            g1 += crh->checkFlag(EcalRecHit::kHasSwitchToGain1);
        }

        if(g1 > 0) event_.photon_gain[i] = 1;
        else if(g6 > 0) event_.photon_gain[i] = 6;
        else event_.photon_gain[i] = 12;
        event_.photon_r9[i] = photon->r9();

        event_.photon_pt[i] = photon->pt();
        event_.photon_eta[i] = photon->eta();
        event_.photon_phi[i] = photon->phi();
        event_.photon_sc_eta[i] = photon->superCluster()->eta();
        event_.photon_sc_phi[i] = photon->superCluster()->phi();

        if (egm_corrected_) 
        {
            const auto calibrated_photon = calibratedPhotons->ptrAt(i);
            event_.photon_corrected_pt[i] = calibrated_photon->pt();
        }
        else 
        {
            event_.photon_corrected_pt[i] = photon->pt();
        }

        event_.photon_ChIsoEa[i] = (double)(*phoChargedIsolationMap)[photon];
        event_.photon_NhIsoEa[i] = (double)(*phoNeutralHadronIsolationMap)[photon];
        event_.photon_PhIsoEa[i] = (double)(*phoPhotonIsolationMap)[photon];

        event_.photon_mva_value[i] = (*mvaValues)[photon];
        event_.photon_mva_category[i] = (*mvaCategories)[photon];

        event_.photon_pass_cutbased_loose[i] = (*loose_id_decisions)[photon];
        event_.photon_pass_cutbased_medium[i] = (*medium_id_decisions)[photon];
        event_.photon_pass_cutbased_tight[i] = (*tight_id_decisions)[photon];
        event_.photon_pass_mva_wp90[i] = (*wp90_id_decisions)[photon];
        event_.photon_pass_mva_wp80[i] = (*wp80_id_decisions)[photon];

        // event_.photon_HoverE                = photon->hadTowOverEm();
        event_.photon_HoverE[i] = photon->hadronicOverEm();
        event_.photon_Full5x5_SigmaIEtaIEta[i] = photon->full5x5_sigmaIetaIeta();

        event_.photon_ChIso[i] = photon->chargedHadronIso(); //chIso;
        event_.photon_NhIso[i] = photon->neutralHadronIso();//nhIso;
        event_.photon_PhIso[i] = photon->photonIso();//phIso;

        event_.photon_has_pixel_seed[i] = photon->hasPixelSeed();
        event_.photon_pass_conversion_veto[i] = photon->passElectronVeto();
    }
}
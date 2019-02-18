#include "Physics/NtupleMaker/interface/NtupleMaker.h"

void NtupleMaker::FillWithPhotons(const edm::Event& iEvent)
{
    edm::Handle<edm::View<pat::Photon>> photons;
    iEvent.getByToken(photons_token_, photons);

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
            event_.photon_corrected_pt[i] = photon->pt() * photon->userFloat("ecalEnergyPostCorr") / photon->energy();;
        }
        else 
        {
            event_.photon_corrected_pt[i] = photon->pt();
        }

        event_.photon_ChIsoEa[i] = photon->userFloat(pho_chiso_name_);
        event_.photon_NhIsoEa[i] = photon->userFloat(pho_nhiso_name_);
        event_.photon_PhIsoEa[i] = photon->userFloat(pho_phiso_name_);

        event_.photon_mva_value[i] = photon->userFloat(pho_mva_value_name_);
        event_.photon_mva_category[i] = photon->userInt(pho_mva_category_name_);

        event_.photon_pass_cutbased_loose[i] = photon->photonID(pho_cutbased_loose_id_name_);
        event_.photon_pass_cutbased_medium[i] = photon->photonID(pho_cutbased_medium_id_name_);
        event_.photon_pass_cutbased_tight[i] = photon->photonID(pho_cutbased_tight_id_name_);
        event_.photon_pass_mva_wp90[i] = photon->photonID(pho_mva_wp90_id_name_);
        event_.photon_pass_mva_wp80[i] = photon->photonID(pho_mva_wp80_id_name_);

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
#include "Physics/NtupleMaker/interface/NtupleMaker.h"

void NtupleMaker::FillWithElectrons(const edm::Event& iEvent)
{
    edm::Handle<edm::View<pat::Electron>> electrons;
    edm::Handle<edm::View<pat::Electron>> calibratedElectrons;
    iEvent.getByToken(electrons_token_, electrons);
    if (egm_corrected_)
    {
        iEvent.getByToken(calibrated_electrons_token_, calibratedElectrons);
        assert(electrons->size() == calibratedElectrons->size());
    }

    event_.num_electrons = electrons->size();
    if (electrons->size() == 0) return;
    
    edm::Handle<edm::ValueMap<bool>> veto_id_decisions;
    edm::Handle<edm::ValueMap<bool>> loose_id_decisions;
    edm::Handle<edm::ValueMap<bool>> medium_id_decisions;
    edm::Handle<edm::ValueMap<bool>> tight_id_decisions; 
    edm::Handle<edm::ValueMap<bool>> heep_id_decisions; 
    iEvent.getByToken(el_cutbased_veto_id_token_, veto_id_decisions);
    iEvent.getByToken(el_cutbased_loose_id_token_, loose_id_decisions);
    iEvent.getByToken(el_cutbased_medium_id_token_, medium_id_decisions);
    iEvent.getByToken(el_cutbased_tight_id_token_, tight_id_decisions);
    iEvent.getByToken(el_cutbased_heep_id_token_, heep_id_decisions);

    edm::Handle<edm::ValueMap<float> > mvaValues;
    edm::Handle<edm::ValueMap<int> > mvaCategories;
    edm::Handle<edm::ValueMap<bool> > wp90_id_decisions;
    edm::Handle<edm::ValueMap<bool> > wp80_id_decisions;
    iEvent.getByToken(el_mva_value_token_,mvaValues);
    iEvent.getByToken(el_mva_category_token_,mvaCategories);
    iEvent.getByToken(el_mva_wp90_id_token_, wp90_id_decisions);
    iEvent.getByToken(el_mva_wp80_id_token_, wp80_id_decisions);

    edm::Handle<pat::PackedCandidateCollection> pfcands;
    edm::Handle<double> rho_for_pfiso;
    edm::Handle<double> rho_for_miniiso;
    iEvent.getByToken(pfcandidates_token_, pfcands);
    iEvent.getByToken(rho_token_, rho_for_pfiso);
    iEvent.getByToken(rho_for_miniiso_token_, rho_for_miniiso);
    
    event_.rho = *rho_for_pfiso;

    edm::Handle<std::vector<reco::Conversion>> conversions;
    iEvent.getByToken(conversions_token_, conversions);

    edm::Handle<EcalRecHitCollection> ecalCalibHitEB_;
    iEvent.getByToken(ecalCalibHitEBToken_,   ecalCalibHitEB_);

    
    for (unsigned idx = 0; idx < electrons->size(); ++idx)
    {
        const auto electron = electrons->ptrAt(idx);

        /// GAIN & R9 ///
        const auto & hitsAndFractions = electron->superCluster()->hitsAndFractions();
        int g1 = 0;
        int g6 = 0;

        for (const auto & hnf : hitsAndFractions)
        {
            auto crh = ecalCalibHitEB_->find(hnf.first);
            if (crh == ecalCalibHitEB_->end()) continue;
            g6 += crh->checkFlag(EcalRecHit::kHasSwitchToGain6);
            g1 += crh->checkFlag(EcalRecHit::kHasSwitchToGain1);
        }

        if(g1 > 0) event_.electron_gain[idx] = 1;
        else if(g6 > 0) event_.electron_gain[idx] = 6;
        else event_.electron_gain[idx] = 12;
        event_.electron_r9[idx] = electron->r9();

        event_.electron_pt[idx]     = electron->pt();
        event_.electron_eta[idx]    = electron->eta();
        event_.electron_phi[idx]    = electron->phi();
        event_.electron_charge[idx] = electron->charge();

        if (egm_corrected_)
        {
            const auto calibrated_electron = calibratedElectrons->ptrAt(idx);
            event_.electron_corrected_pt[idx] = calibrated_electron->pt();
        }
        else
        {
            event_.electron_corrected_pt[idx] = electron->pt();
        }
        
        event_.electron_pass_cutbased_veto[idx] = (*veto_id_decisions)[electron];
        event_.electron_pass_cutbased_loose[idx] = (*loose_id_decisions)[electron];
        event_.electron_pass_cutbased_medium[idx] = (*medium_id_decisions)[electron];
        event_.electron_pass_cutbased_tight[idx] = (*tight_id_decisions)[electron];
        if (heep_id_decisions.isValid()) event_.electron_pass_cutbased_heep[idx] = (*heep_id_decisions)[electron];
        event_.electron_mva_value[idx] = (*mvaValues)[electron];
        event_.electron_mva_category[idx] = (*mvaCategories)[electron];
        event_.electron_pass_mva_wp90[idx] = (*wp90_id_decisions)[electron];
        event_.electron_pass_mva_wp80[idx] = (*wp80_id_decisions)[electron];

        event_.electron_sc_eta[idx] = electron->superCluster()->eta();
        event_.electron_sc_phi[idx] = electron->superCluster()->phi();

        // ECAL
        event_.electron_sigmaIetaIeta[idx] = electron->full5x5_sigmaIetaIeta();
        event_.electron_E1x5[idx]          = electron->e1x5();
        event_.electron_E2x5[idx]          = electron->e2x5Max();
        event_.electron_E5x5[idx]          = electron->e5x5();
        event_.electron_hOverE[idx]        = electron->hadronicOverEm();

        // ECAL + Track
        event_.electron_dEtaInSeed[idx] = electron->deltaEtaSuperClusterTrackAtVtx() - electron->superCluster()->eta() + electron->superCluster()->seed()->eta();
        event_.electron_dPhiIn[idx] = electron->deltaPhiSuperClusterTrackAtVtx();
        if( electron->ecalEnergy() == 0 )
        {
            event_.electron_ooEmooP[idx] = 1e30;
        }
        else if( !std::isfinite(electron->ecalEnergy()))
        {
            event_.electron_ooEmooP[idx] = 1e30;
        }
        else
        {
            event_.electron_ooEmooP[idx] = fabs(1.0 - electron->eSuperClusterOverP())/electron->ecalEnergy();
        }

        // Isolation
        GsfElectron::PflowIsolationVariables pfIso = electron->pfIsolationVariables();

        // Compute isolation with delta beta correction for PU
        event_.electron_isoChargedHadrons[idx] = pfIso.sumChargedHadronPt;
        event_.electron_isoNeutralHadrons[idx] = pfIso.sumNeutralHadronEt;
        event_.electron_isoPhotons[idx]        = pfIso.sumPhotonEt;
        event_.electron_isoChargedFromPU[idx]  = pfIso.sumPUPt;


        // The effective areas constants file in the local release or default CMSSW, whichever is found
        edm::FileInPath eaConstantsFile(ea_file_path_);
        EffectiveAreas effectiveAreas(eaConstantsFile.fullPath());
        float abseta = fabs(electron->superCluster()->eta());
        float eA = effectiveAreas.getEffectiveArea(abseta);

        event_.electron_isoDeltaBeta[idx] = pfIso.sumChargedHadronPt + max<float>(0.0, pfIso.sumNeutralHadronEt + pfIso.sumPhotonEt - 0.5 * pfIso.sumPUPt);
        event_.electron_isoRho[idx] = pfIso.sumChargedHadronPt + max<float>(0.0, pfIso.sumNeutralHadronEt + pfIso.sumPhotonEt - event_.rho * eA);

        GsfElectron::IsolationVariables oldIso03 = electron->dr03IsolationVariables();
        GsfElectron::IsolationVariables oldIso04 = electron->dr04IsolationVariables();

        event_.electron_dr03ecalRecHitSumEt[idx] = oldIso03.ecalRecHitSumEt;
        event_.electron_dr03hcalDepth1TowerSumEt[idx] = oldIso03.hcalDepth1TowerSumEt;
        event_.electron_dr03hcalDepth1TowerSumEtBc[idx] = oldIso03.hcalDepth1TowerSumEtBc;
        event_.electron_dr03hcalDepth2TowerSumEt[idx] = oldIso03.hcalDepth2TowerSumEt;
        event_.electron_dr03hcalDepth2TowerSumEtBc[idx] = oldIso03.hcalDepth2TowerSumEtBc;
        event_.electron_dr03tkSumPt[idx] = oldIso03.tkSumPt;

        event_.electron_dr04ecalRecHitSumEt[idx] = oldIso04.ecalRecHitSumEt;
        event_.electron_dr04hcalDepth1TowerSumEt[idx] = oldIso04.hcalDepth1TowerSumEt;
        event_.electron_dr04hcalDepth1TowerSumEtBc[idx] = oldIso04.hcalDepth1TowerSumEtBc;
        event_.electron_dr04hcalDepth2TowerSumEt[idx] = oldIso04.hcalDepth2TowerSumEt;
        event_.electron_dr04hcalDepth2TowerSumEtBc[idx] = oldIso04.hcalDepth2TowerSumEtBc;
        event_.electron_dr04tkSumPt[idx] = oldIso04.tkSumPt;

        event_.electron_d0[idx] = (-1) * electron->gsfTrack()->dxy(vtx.position());
        event_.electron_expectedMissingInnerHits[idx] = electron->gsfTrack()->hitPattern().numberOfHits(reco::HitPattern::MISSING_INNER_HITS);
        event_.electron_passConversionVeto[idx] = !ConversionTools::hasMatchedConversion(*electron, conversions, beamSpotHandle->position());

        event_.electron_miniiso_ea[idx] = GetMiniIsolation(pfcands, dynamic_cast<const reco::Candidate *>(&(electrons->at(idx))), 0.05, 0.2, 10., *rho_for_miniiso, true);
        event_.electron_miniiso_dbeta[idx] = GetMiniIsolation(pfcands, dynamic_cast<const reco::Candidate *>(&(electrons->at(idx))), 0.05, 0.2, 10., *rho_for_miniiso, false);
    }
}
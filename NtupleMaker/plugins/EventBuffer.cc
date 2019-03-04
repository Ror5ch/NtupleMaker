#ifdef _NOTCMSSW_
#include "event/EventBuffer.h"
#else
#include "Physics/NtupleMaker/interface/EventBuffer.h"
#endif

void EventBuffer::Initialize()
{
    run = -999;
    ls = -999;
    event = -999;
    num_vertices = -999;
    num_pu = -999;
    num_pu_in_time = -999;
    rho = -999;
    weight = -999;

    num_filters = -999;
    num_triggers = -999;
    num_electrons = -999;
    num_muons = -999;
    num_photons = -999;
    num_gen_particles = -999;
    num_jets = -999;
    num_protons = -999;
    num_local_tracks = -999;

    filter_name->clear();
    trigger_name->clear();

    for (auto i = 0; i < EventBuffer::MAX_SIZE; ++i)
    {
        filter_decision[i] = false;
        trigger_decision[i] = false;

        electron_pt[i] = -999;
        electron_eta[i] = -999;
        electron_phi[i] = -999;
        electron_charge[i] = -999;
        electron_pass_cutbased_veto[i] = false;
        electron_pass_cutbased_loose[i] = false;
        electron_pass_cutbased_medium[i] = false;
        electron_pass_cutbased_tight[i] = false;
        electron_pass_cutbased_heep[i] = false;
        electron_mva_value[i] = -999;
        electron_mva_category[i] = -999;
        electron_pass_mva_wp80[i] = false;
        electron_pass_mva_wp90[i] = false;
        electron_sc_eta[i] = -999;
        electron_sc_phi[i] = -999;
        electron_sigmaIetaIeta[i] = -999;
        electron_E1x5[i] = -999;
        electron_E2x5[i] = -999;
        electron_E5x5[i] = -999;
        electron_hOverE[i] = -999;
        electron_dEtaInSeed[i] = -999;
        electron_dPhiIn[i] = -999;
        electron_ooEmooP[i] = -999;
        electron_isoChargedHadrons[i] = -999;
        electron_isoNeutralHadrons[i] = -999;
        electron_isoPhotons[i] = -999;
        electron_isoChargedFromPU[i] = -999;
        electron_isoDeltaBeta[i] = -999;
        electron_isoRho[i] = -999;
        electron_dr03ecalRecHitSumEt[i] = -999;
        electron_dr03hcalDepth1TowerSumEt[i] = -999;
        electron_dr03hcalDepth1TowerSumEtBc[i] = -999;
        electron_dr03hcalDepth2TowerSumEt[i] = -999;
        electron_dr03hcalDepth2TowerSumEtBc[i] = -999;
        electron_dr03tkSumPt[i] = -999;
        electron_dr04ecalRecHitSumEt[i] = -999;
        electron_dr04hcalDepth1TowerSumEt[i] = -999;
        electron_dr04hcalDepth1TowerSumEtBc[i] = -999;
        electron_dr04hcalDepth2TowerSumEt[i] = -999;
        electron_dr04hcalDepth2TowerSumEtBc[i] = -999;
        electron_dr04tkSumPt[i] = -999;
        electron_d0[i] = -999;
        electron_expectedMissingInnerHits[i] = -999;
        electron_passConversionVeto[i] = false;
        electron_miniiso_ea[i]= -999;
        electron_miniiso_dbeta[i]= -999;
        electron_gain[i] = -999;
        electron_r9[i] = -999;

        muon_isGlobalMuon[i] = false;
        muon_isStandAloneMuon[i] = false;
        muon_isTrackerMuon[i] = false;
        muon_isPFMuon[i] = false;
        muon_pt[i]= -999;
        muon_corrected_pt[i]= -999;
        muon_phi[i]= -999;
        muon_eta[i]= -999;
        muon_charge[i] = -999;
        muon_numberOfChambers[i] = -999;
        muon_stationMask[i] = -999;
        muon_numberOfMatchedStations[i] = -999;
        muon_global_pt[i] = -999;
        muon_global_ptError[i] = -999;
        muon_global_phi[i] = -999;
        muon_global_eta[i] = -999;
        muon_global_normalizedChi2[i] = -999;
        muon_global_numberOfValidPixelHits[i] = -999;
        muon_global_trackerLayersWithMeasurement[i] = -999;
        muon_global_numberOfValidMuonHits[i] = -999;
        muon_global_dxy_vtx[i] = -999;
        muon_global_dz_vtx[i] = -999;
        muon_global_validFraction[i] = -999;
        muon_inner_pt[i] = -999;
        muon_inner_ptError[i] = -999;
        muon_inner_phi[i] = -999;
        muon_inner_eta[i] = -999;
        muon_inner_normalizedChi2[i] = -999;
        muon_inner_numberOfValidPixelHits[i] = -999;
        muon_inner_trackerLayersWithMeasurement[i] = -999;
        muon_inner_numberOfValidMuonHits[i] = -999;
        muon_inner_dxy_vtx[i] = -999;
        muon_inner_dz_vtx[i] = -999;
        muon_inner_validFraction[i] = -999;
        muon_outer_pt[i] = -999;
        muon_outer_ptError[i] = -999;
        muon_outer_phi[i] = -999;
        muon_outer_eta[i] = -999;
        muon_outer_normalizedChi2[i] = -999;
        muon_outer_numberOfValidPixelHits[i] = -999;
        muon_outer_trackerLayersWithMeasurement[i] = -999;
        muon_outer_numberOfValidMuonHits[i] = -999;
        muon_outer_dxy_vtx[i] = -999;
        muon_outer_dz_vtx[i] = -999;
        muon_outer_validFraction[i] = -999;
        muon_best_pt[i] = -999;
        muon_best_ptError[i] = -999;
        muon_best_phi[i] = -999;
        muon_best_eta[i] = -999;
        muon_best_normalizedChi2[i] = -999;
        muon_best_numberOfValidPixelHits[i] = -999;
        muon_best_trackerLayersWithMeasurement[i] = -999;
        muon_best_numberOfValidMuonHits[i] = -999;
        muon_best_dxy_vtx[i] = -999;
        muon_best_dz_vtx[i] = -999;
        muon_best_validFraction[i] = -999;
        muon_tunep_pt[i] = -999;
        muon_tunep_ptError[i] = -999;
        muon_tunep_phi[i] = -999;
        muon_tunep_eta[i] = -999;
        muon_tunep_normalizedChi2[i] = -999;
        muon_tunep_numberOfValidPixelHits[i] = -999;
        muon_tunep_trackerLayersWithMeasurement[i] = -999;
        muon_tunep_numberOfValidMuonHits[i] = -999;
        muon_tunep_dxy_vtx[i] = -999;
        muon_tunep_dz_vtx[i] = -999;
        muon_tunep_validFraction[i] = -999;
        muon_isolationR03_sumpt[i] = -999;
        muon_isolationR03_hadEt[i] = -999;
        muon_isolationR03_emEt[i] = -999;
        muon_pfIsolationR04_sumChargedHadronPt[i] = -999;
        muon_pfIsolationR04_sumNeutralHadronEt[i] = -999;
        muon_pfIsolationR04_sumPhotonEt[i] = -999;
        muon_pfIsolationR04_sumPUPt[i] = -999;
        muon_miniiso_ea[i] = -999;
        muon_miniiso_dbeta[i] = -999;
        muon_segmentCompatibility[i] = -999;
        muon_quality_chi2LocalPosition[i] = -999;
        muon_quality_trkKink[i] = -999;

        photon_pt[i] = -999;
        photon_corrected_pt[i] = -999;
        photon_eta[i] = -999;
        photon_phi[i] = -999;
        photon_sc_eta[i] = -999;
        photon_sc_phi[i] = -999;
        photon_HoverE[i] = -999;
        photon_Full5x5_SigmaIEtaIEta[i] = -999;
        photon_ChIso[i] = -999;
        photon_NhIso[i] = -999;
        photon_PhIso[i] = -999;
        photon_ChIsoEa[i] = -999;
        photon_NhIsoEa[i] = -999;
        photon_PhIsoEa[i] = -999;
        photon_mva_value[i] = -999;
        photon_mva_category[i] = -999;
        photon_has_pixel_seed[i] = false;
        photon_pass_conversion_veto[i] = false;
        photon_pass_cutbased_loose[i] = false;
        photon_pass_cutbased_medium[i] = false;
        photon_pass_cutbased_tight[i] = false;
        photon_pass_mva_wp80[i] = false;
        photon_pass_mva_wp90[i] = false;
        photon_r9[i] = -999;
        photon_gain[i] = -999;

        gen_particle_pt[i] = -999;
        gen_particle_eta[i] = -999;
        gen_particle_phi[i] = -999;
        gen_particle_energy[i] = -999;
        gen_particle_mass[i] = -999;
        gen_particle_charge[i] = -999;
        gen_particle_id[i] = -999;
        gen_particle_status[i] = -999;
        gen_particle_mother[i] = -999;
        gen_particle_fromHardProcessFinalState[i] = false;
        gen_particle_fromHardProcessDecayed[i] = false;
        gen_particle_fromHardProcessBeforeFSR[i] = false;
        gen_particle_isHardProcess[i] = false;
        gen_particle_isLastCopy[i] = false;
        gen_particle_isLastCopyBeforeFSR[i] = false;
        gen_particle_isPromptDecayed[i] = false;
        gen_particle_isPromptFinalState[i] = false;
        gen_particle_isDirectHardProcessTauDecayProductFinalState[i] = false;
        gen_particle_isDirectPromptTauDecayProductFinalState[i] = false;

        jet_pt[i] = -999;
        jet_eta[i] = -999;
        jet_phi[i] = -999;
        jet_charge[i] = -999;
        jet_flavor[i] = -999;
        jet_bTag[i] = -999;
        jet_CHF[i] = -999;
        jet_NHF[i] = -999;
        jet_NEMF[i] = -999;
        jet_CEMF[i] = -999;
        jet_CHM[i] = -999;
        jet_NHM[i] = -999;
        jet_MUF[i] = -999;

        proton_xi[i] = -999;
        proton_method[i] = -999;
        proton_lhcSector[i] = -999;
        proton_isValid[i] = false;

        local_track_rpId[i] = -999;
        local_track_x[i] = -999;
        local_track_x_unc[i] = -999;
        local_track_y[i] = -999;
        local_track_y_unc[i] = -999;
        local_track_tx[i] = -999;
        local_track_tx_unc[i] = -999;
        local_track_ty[i] = -999;
        local_track_ty_unc[i] = -999;
        local_track_chiSquaredOverNDF[i] = -999;
    }
}

void EventBuffer::SetBranchWrite(TTree* tree)
{
    tree->Branch("run", &run);
    tree->Branch("ls", &ls);
    tree->Branch("event", &event);
    tree->Branch("num_vertices", &num_vertices);
    tree->Branch("rho", &rho);
    tree->Branch("num_pu", &num_pu);
    tree->Branch("num_pu_in_time", &num_pu_in_time);
    tree->Branch("weight", &weight);

    tree->Branch("num_filters", &num_filters);
    tree->Branch("filter_name", &filter_name);
    tree->Branch("filter_decision", filter_decision, "filter_decision[num_filters]/O");

    tree->Branch("num_triggers", &num_triggers);
    tree->Branch("trigger_name", &trigger_name);
    tree->Branch("trigger_decision", trigger_decision, "trigger_decision[num_triggers]/O");

    tree->Branch("num_electrons", &num_electrons);
    tree->Branch("electron_pt", electron_pt, "electron_pt[num_electrons]/D");
    tree->Branch("electron_corrected_pt", electron_corrected_pt, "electron_corrected_pt[num_electrons]/D");
    tree->Branch("electron_eta", electron_eta, "electron_eta[num_electrons]/D");
    tree->Branch("electron_phi", electron_phi, "electron_phi[num_electrons]/D");
    tree->Branch("electron_sc_eta", electron_sc_eta, "electron_sc_eta[num_electrons]/D");
    tree->Branch("electron_sc_phi", electron_sc_phi, "electron_sc_phi[num_electrons]/D");
    
    tree->Branch("electron_charge", electron_charge, "electron_charge[num_electrons]/I");
    tree->Branch("electron_pass_cutbased_veto", electron_pass_cutbased_veto, "electron_pass_cutbased_veto[num_electrons]/O");
    tree->Branch("electron_pass_cutbased_loose", electron_pass_cutbased_loose, "electron_pass_cutbased_loose[num_electrons]/O");
    tree->Branch("electron_pass_cutbased_medium", electron_pass_cutbased_medium, "electron_pass_cutbased_medium[num_electrons]/O");
    tree->Branch("electron_pass_cutbased_tight", electron_pass_cutbased_tight, "electron_pass_cutbased_tight[num_electrons]/O");
    tree->Branch("electron_pass_cutbased_heep", electron_pass_cutbased_heep, "electron_pass_cutbased_heep[num_electrons]/O");
    tree->Branch("electron_pass_mva_wp80", electron_pass_mva_wp80, "electron_pass_mva_wp80[num_electrons]/O");
    tree->Branch("electron_pass_mva_wp90", electron_pass_mva_wp90, "electron_pass_mva_wp90[num_electrons]/O");
    tree->Branch("electron_mva_value", electron_mva_value, "electron_mva_value[num_electrons]/D");
    tree->Branch("electron_mva_category", electron_mva_category, "electron_mva_category[num_electrons]/I");


    tree->Branch("electron_sigmaIetaIeta", electron_sigmaIetaIeta, "electron_sigmaIetaIeta[num_electrons]/D");
    tree->Branch("electron_E1x5", electron_E1x5, "electron_E1x5[num_electrons]/D");
    tree->Branch("electron_E2x5", electron_E2x5, "electron_E2x5[num_electrons]/D");
    tree->Branch("electron_E5x5", electron_E5x5, "electron_E5x5[num_electrons]/D");
    tree->Branch("electron_hOverE", electron_hOverE, "electron_hOverE[num_electrons]/D");
    tree->Branch("electron_dEtaInSeed", electron_dEtaInSeed, "electron_dEtaInSeed[num_electrons]/D");
    tree->Branch("electron_dPhiIn", electron_dPhiIn, "electron_dPhiIn[num_electrons]/D");
    tree->Branch("electron_ooEmooP", electron_ooEmooP, "electron_ooEmooP[num_electrons]/D");
    tree->Branch("electron_d0", electron_d0, "electron_d0[num_electrons]/D");
    tree->Branch("electron_expectedMissingInnerHits", electron_expectedMissingInnerHits, "electron_expectedMissingInnerHits[num_electrons]/I");
    tree->Branch("electron_passConversionVeto", electron_passConversionVeto, "electron_passConversionVeto[num_electrons]/O");

    tree->Branch("electron_isoChargedHadrons", electron_isoChargedHadrons, "electron_isoChargedHadrons[num_electrons]/D");
    tree->Branch("electron_isoNeutralHadrons", electron_isoNeutralHadrons, "electron_isoNeutralHadrons[num_electrons]/D");
    tree->Branch("electron_isoPhotons", electron_isoPhotons, "electron_isoPhotons[num_electrons]/D");
    tree->Branch("electron_isoChargedFromPU", electron_isoChargedFromPU, "electron_isoChargedFromPU[num_electrons]/D");
    tree->Branch("electron_isoDeltaBeta", electron_isoDeltaBeta, "electron_isoDeltaBeta[num_electrons]/D");
    tree->Branch("electron_isoRho", electron_isoRho, "electron_isoRho[num_electrons]/D");
    tree->Branch("electron_dr03ecalRecHitSumEt", electron_dr03ecalRecHitSumEt, "electron_dr03ecalRecHitSumEt[num_electrons]/D");
    tree->Branch("electron_dr03hcalDepth1TowerSumEt", electron_dr03hcalDepth1TowerSumEt, "electron_dr03hcalDepth1TowerSumEt[num_electrons]/D");
    tree->Branch("electron_dr03hcalDepth1TowerSumEtBc", electron_dr03hcalDepth1TowerSumEtBc, "electron_dr03hcalDepth1TowerSumEtBc[num_electrons]/D");
    tree->Branch("electron_dr03hcalDepth2TowerSumEt", electron_dr03hcalDepth2TowerSumEt, "electron_dr03hcalDepth2TowerSumEt[num_electrons]/D");
    tree->Branch("electron_dr03hcalDepth2TowerSumEtBc", electron_dr03hcalDepth2TowerSumEtBc, "electron_dr03hcalDepth2TowerSumEtBc[num_electrons]/D");
    tree->Branch("electron_dr03tkSumPt", electron_dr03tkSumPt, "electron_dr03tkSumPt[num_electrons]/D");
    tree->Branch("electron_dr04ecalRecHitSumEt", electron_dr04ecalRecHitSumEt, "electron_dr04ecalRecHitSumEt[num_electrons]/D");
    tree->Branch("electron_dr04hcalDepth1TowerSumEt", electron_dr04hcalDepth1TowerSumEt, "electron_dr04hcalDepth1TowerSumEt[num_electrons]/D");
    tree->Branch("electron_dr04hcalDepth1TowerSumEtBc", electron_dr04hcalDepth1TowerSumEtBc, "electron_dr04hcalDepth1TowerSumEtBc[num_electrons]/D");
    tree->Branch("electron_dr04hcalDepth2TowerSumEt", electron_dr04hcalDepth2TowerSumEt, "electron_dr04hcalDepth2TowerSumEt[num_electrons]/D");
    tree->Branch("electron_dr04hcalDepth1TowerSumEtBc", electron_dr04hcalDepth1TowerSumEtBc, "electron_dr04hcalDepth1TowerSumEtBc[num_electrons]/D");
    tree->Branch("electron_dr04tkSumPt", electron_dr04tkSumPt, "electron_dr04tkSumPt[num_electrons]/D");
    
    tree->Branch("electron_miniiso_ea", electron_miniiso_ea, "electron_miniiso_ea[num_electrons]/D");
    tree->Branch("electron_miniiso_dbeta", electron_miniiso_dbeta, "electron_miniiso_dbeta[num_electrons]/D");
    
    tree->Branch("electron_gain", electron_gain, "electron_gain[num_electrons]/I");
    tree->Branch("electron_r9", electron_r9, "electron_r9[num_electrons]/D");

    tree->Branch("num_muons", &num_muons);
    tree->Branch("muon_isGlobalMuon", muon_isGlobalMuon, "muon_isGlobalMuon[num_muons]/O");
    tree->Branch("muon_isStandAloneMuon", muon_isStandAloneMuon, "muon_isStandAloneMuon[num_muons]/O");
    tree->Branch("muon_isTrackerMuon", muon_isTrackerMuon, "muon_isTrackerMuon[num_muons]/O");
    tree->Branch("muon_isPFMuon", muon_isPFMuon, "muon_isPFMuon[num_muons]/O");

    tree->Branch("muon_pt", muon_pt, "muon_pt[num_muons]/D");
    tree->Branch("muon_corrected_pt", muon_corrected_pt, "muon_corrected_pt[num_muons]/D");
    tree->Branch("muon_eta", muon_eta, "muon_eta[num_muons]/D");
    tree->Branch("muon_phi", muon_phi, "muon_phi[num_muons]/D");
    tree->Branch("muon_charge", muon_charge, "muon_charge[num_muons]/I");

    tree->Branch("muon_numberOfChambers", muon_numberOfChambers, "muon_numberOfChambers[num_muons]/I");
    tree->Branch("muon_stationMask", muon_stationMask, "muon_stationMask[num_muons]/I");
    tree->Branch("muon_numberOfMatchedStations", muon_numberOfMatchedStations, "muon_numberOfMatchedStations[num_muons]/I");

    tree->Branch("muon_global_pt", muon_global_pt, "muon_global_pt[num_muons]/D");
    tree->Branch("muon_global_ptError", muon_global_ptError, "muon_global_ptError[num_muons]/D");
    tree->Branch("muon_global_phi", muon_global_phi, "muon_global_phi[num_muons]/D");
    tree->Branch("muon_global_eta", muon_global_eta, "muon_global_eta[num_muons]/D");
    tree->Branch("muon_global_normalizedChi2", muon_global_normalizedChi2, "muon_global_normalizedChi2[num_muons]/D");
    tree->Branch("muon_global_numberOfValidPixelHits", muon_global_numberOfValidPixelHits, "muon_global_numberOfValidPixelHits[num_muons]/I");
    tree->Branch("muon_global_numberOfValidMuonHits", muon_global_numberOfValidMuonHits, "muon_global_numberOfValidMuonHits[num_muons]/I");
    tree->Branch("muon_global_trackerLayersWithMeasurement", muon_global_trackerLayersWithMeasurement, "muon_global_trackerLayersWithMeasurement[num_muons]/I");
    tree->Branch("muon_global_dxy_vtx", muon_global_dxy_vtx, "muon_global_dxy_vtx[num_muons]/D");
    tree->Branch("muon_global_dz_vtx", muon_global_dz_vtx, "muon_global_dz_vtx[num_muons]/D");
    tree->Branch("muon_global_validFraction", muon_global_validFraction, "muon_global_validFraction[num_muons]/D");

    tree->Branch("muon_inner_pt", muon_inner_pt, "muon_inner_pt[num_muons]/D");
    tree->Branch("muon_inner_ptError", muon_inner_ptError, "muon_inner_ptError[num_muons]/D");
    tree->Branch("muon_inner_phi", muon_inner_phi, "muon_inner_phi[num_muons]/D");
    tree->Branch("muon_inner_eta", muon_inner_eta, "muon_inner_eta[num_muons]/D");
    tree->Branch("muon_inner_normalizedChi2", muon_inner_normalizedChi2, "muon_inner_normalizedChi2[num_muons]/D");
    tree->Branch("muon_inner_numberOfValidPixelHits", muon_inner_numberOfValidPixelHits, "muon_inner_numberOfValidPixelHits[num_muons]/I");
    tree->Branch("muon_inner_numberOfValidMuonHits", muon_inner_numberOfValidMuonHits, "muon_inner_numberOfValidMuonHits[num_muons]/I");
    tree->Branch("muon_inner_trackerLayersWithMeasurement", muon_inner_trackerLayersWithMeasurement, "muon_inner_trackerLayersWithMeasurement[num_muons]/I");
    tree->Branch("muon_inner_dxy_vtx", muon_inner_dxy_vtx, "muon_inner_dxy_vtx[num_muons]/D");
    tree->Branch("muon_inner_dz_vtx", muon_inner_dz_vtx, "muon_inner_dz_vtx[num_muons]/D");
    tree->Branch("muon_inner_validFraction", muon_inner_validFraction, "muon_inner_validFraction[num_muons]/D");

    tree->Branch("muon_outer_pt", muon_outer_pt, "muon_outer_pt[num_muons]/D");
    tree->Branch("muon_outer_ptError", muon_outer_ptError, "muon_outer_ptError[num_muons]/D");
    tree->Branch("muon_outer_phi", muon_outer_phi, "muon_outer_phi[num_muons]/D");
    tree->Branch("muon_outer_eta", muon_outer_eta, "muon_outer_eta[num_muons]/D");
    tree->Branch("muon_outer_normalizedChi2", muon_outer_normalizedChi2, "muon_outer_normalizedChi2[num_muons]/D");
    tree->Branch("muon_outer_numberOfValidPixelHits", muon_outer_numberOfValidPixelHits, "muon_outer_numberOfValidPixelHits[num_muons]/I");
    tree->Branch("muon_outer_numberOfValidMuonHits", muon_outer_numberOfValidMuonHits, "muon_outer_numberOfValidMuonHits[num_muons]/I");
    tree->Branch("muon_outer_trackerLayersWithMeasurement", muon_outer_trackerLayersWithMeasurement, "muon_outer_trackerLayersWithMeasurement[num_muons]/I");
    tree->Branch("muon_outer_dxy_vtx", muon_outer_dxy_vtx, "muon_outer_dxy_vtx[num_muons]/D");
    tree->Branch("muon_outer_dz_vtx", muon_outer_dz_vtx, "muon_outer_dz_vtx[num_muons]/D");
    tree->Branch("muon_outer_validFraction", muon_outer_validFraction, "muon_outer_validFraction[num_muons]/D");

    tree->Branch("muon_best_pt", muon_best_pt, "muon_best_pt[num_muons]/D");
    tree->Branch("muon_best_ptError", muon_best_ptError, "muon_best_ptError[num_muons]/D");
    tree->Branch("muon_best_phi", muon_best_phi, "muon_best_phi[num_muons]/D");
    tree->Branch("muon_best_eta", muon_best_eta, "muon_best_eta[num_muons]/D");
    tree->Branch("muon_best_normalizedChi2", muon_best_normalizedChi2, "muon_best_normalizedChi2[num_muons]/D");
    tree->Branch("muon_best_numberOfValidPixelHits", muon_best_numberOfValidPixelHits, "muon_best_numberOfValidPixelHits[num_muons]/I");
    tree->Branch("muon_best_numberOfValidMuonHits", muon_best_numberOfValidMuonHits, "muon_best_numberOfValidMuonHits[num_muons]/I");
    tree->Branch("muon_best_trackerLayersWithMeasurement", muon_best_trackerLayersWithMeasurement, "muon_best_trackerLayersWithMeasurement[num_muons]/I");
    tree->Branch("muon_best_dxy_vtx", muon_best_dxy_vtx, "muon_best_dxy_vtx[num_muons]/D");
    tree->Branch("muon_best_dz_vtx", muon_best_dz_vtx, "muon_best_dz_vtx[num_muons]/D");
    tree->Branch("muon_best_validFraction", muon_best_validFraction, "muon_best_validFraction[num_muons]/D");

    tree->Branch("muon_tunep_pt", muon_tunep_pt, "muon_tunep_pt[num_muons]/D");
    tree->Branch("muon_tunep_ptError", muon_tunep_ptError, "muon_tunep_ptError[num_muons]/D");
    tree->Branch("muon_tunep_phi", muon_tunep_phi, "muon_tunep_phi[num_muons]/D");
    tree->Branch("muon_tunep_eta", muon_tunep_eta, "muon_tunep_eta[num_muons]/D");
    tree->Branch("muon_tunep_normalizedChi2", muon_tunep_normalizedChi2, "muon_tunep_normalizedChi2[num_muons]/D");
    tree->Branch("muon_tunep_numberOfValidPixelHits", muon_tunep_numberOfValidPixelHits, "muon_tunep_numberOfValidPixelHits[num_muons]/I");
    tree->Branch("muon_tunep_numberOfValidMuonHits", muon_tunep_numberOfValidMuonHits, "muon_tunep_numberOfValidMuonHits[num_muons]/I");
    tree->Branch("muon_tunep_trackerLayersWithMeasurement", muon_tunep_trackerLayersWithMeasurement, "muon_tunep_trackerLayersWithMeasurement[num_muons]/I");
    tree->Branch("muon_tunep_dxy_vtx", muon_tunep_dxy_vtx, "muon_tunep_dxy_vtx[num_muons]/D");
    tree->Branch("muon_tunep_dz_vtx", muon_tunep_dz_vtx, "muon_tunep_dz_vtx[num_muons]/D");
    tree->Branch("muon_tunep_validFraction", muon_tunep_validFraction, "muon_tunep_validFraction[num_muons]/D");

    tree->Branch("muon_isolationR03_sumpt", muon_isolationR03_sumpt, "muon_isolationR03_sumpt[num_muons]/D");
    tree->Branch("muon_isolationR03_hadEt", muon_isolationR03_hadEt, "muon_isolationR03_hadEt[num_muons]/D");
    tree->Branch("muon_isolationR03_emEt", muon_isolationR03_emEt, "muon_isolationR03_emEt[num_muons]/D");
    tree->Branch("muon_pfIsolationR04_sumPUPt", muon_pfIsolationR04_sumPUPt, "muon_pfIsolationR04_sumPUPt[num_muons]/D");
    tree->Branch("muon_pfIsolationR04_sumPhotonEt", muon_pfIsolationR04_sumPhotonEt, "muon_pfIsolationR04_sumPhotonEt[num_muons]/D");
    tree->Branch("muon_pfIsolationR04_sumChargedHadronPt", muon_pfIsolationR04_sumChargedHadronPt, "muon_pfIsolationR04_sumChargedHadronPt[num_muons]/D");
    tree->Branch("muon_pfIsolationR04_sumNeutralHadronEt", muon_pfIsolationR04_sumNeutralHadronEt, "muon_pfIsolationR04_sumNeutralHadronEt[num_muons]/D");
    tree->Branch("muon_miniiso_ea", muon_miniiso_ea, "muon_miniiso_ea[num_muons]/D");
    tree->Branch("muon_miniiso_dbeta", muon_miniiso_dbeta, "muon_miniiso_dbeta[num_muons]/D");
    tree->Branch("muon_segmentCompatibility", muon_segmentCompatibility, "muon_segmentCompatibility[num_muons]/D");
    tree->Branch("muon_quality_trkKink", muon_quality_trkKink, "muon_quality_trkKink[num_muons]/D");
    tree->Branch("muon_quality_chi2LocalPosition", muon_quality_chi2LocalPosition, "muon_quality_chi2LocalPosition[num_muons]/D");

    tree->Branch("num_photons", &num_photons);
    tree->Branch("photon_pt", photon_pt, "photon_pt[num_photons]/D");
    tree->Branch("photon_corrected_pt", photon_corrected_pt, "photon_corrected_pt[num_photons]/D");
    tree->Branch("photon_eta", photon_eta, "photon_eta[num_photons]/D");
    tree->Branch("photon_phi", photon_phi, "photon_phi[num_photons]/D");
    tree->Branch("photon_sc_eta", photon_sc_eta, "photon_sc_eta[num_photons]/D");
    tree->Branch("photon_sc_phi", photon_sc_phi, "photon_sc_phi[num_photons]/D");
    tree->Branch("photon_has_pixel_seed", photon_has_pixel_seed, "photon_has_pixel_seed[num_photons]/O");
    tree->Branch("photon_pass_conversion_veto", photon_pass_conversion_veto, "photon_pass_conversion_veto[num_photons]/O");
    tree->Branch("photon_pass_cutbased_loose", photon_pass_cutbased_loose, "photon_pass_cutbased_loose[num_photons]/O");
    tree->Branch("photon_pass_cutbased_medium", photon_pass_cutbased_medium, "photon_pass_cutbased_medium[num_photons]/O");
    tree->Branch("photon_pass_cutbased_tight", photon_pass_cutbased_tight, "photon_pass_cutbased_tight[num_photons]/O");
    tree->Branch("photon_mva_value", photon_mva_value, "photon_mva_value[num_photons]/D");
    tree->Branch("photon_mva_category", photon_mva_category, "photon_mva_category[num_photons]/I");
    tree->Branch("photon_pass_mva_wp80", photon_pass_mva_wp80, "photon_pass_mva_wp80[num_photons]/O");
    tree->Branch("photon_pass_mva_wp90", photon_pass_mva_wp90, "photon_pass_mva_wp90[num_photons]/O");
    tree->Branch("photon_HoverE", photon_HoverE, "photon_HoverE[num_photons]/D");
    tree->Branch("photon_Full5x5_SigmaIEtaIEta", photon_Full5x5_SigmaIEtaIEta, "photon_Full5x5_SigmaIEtaIEta[num_photons]/D");
    tree->Branch("photon_ChIso", photon_ChIso, "photon_ChIso[num_photons]/D");
    tree->Branch("photon_NhIso", photon_NhIso, "photon_NhIso[num_photons]/D");
    tree->Branch("photon_PhIso", photon_PhIso, "photon_PhIso[num_photons]/D");
    tree->Branch("photon_ChIsoEa", photon_ChIsoEa, "photon_ChIsoEa[num_photons]/D");
    tree->Branch("photon_NhIsoEa", photon_NhIsoEa, "photon_NhIsoEa[num_photons]/D");
    tree->Branch("photon_PhIsoEa", photon_PhIsoEa, "photon_PhIsoEa[num_photons]/D");
    tree->Branch("photon_gain", photon_gain, "photon_gain[num_photons]/I");
    tree->Branch("photon_r9", photon_r9, "photon_r9[num_photons]/D");

    tree->Branch("num_gen_particles", &num_gen_particles);
    tree->Branch("gen_particle_pt", gen_particle_pt, "gen_particle_pt[num_gen_particles]/D");
    tree->Branch("gen_particle_eta", gen_particle_eta, "gen_particle_eta[num_gen_particles]/D");
    tree->Branch("gen_particle_phi", gen_particle_phi, "gen_particle_phi[num_gen_particles]/D");
    tree->Branch("gen_particle_energy", gen_particle_energy, "gen_particle_energy[num_gen_particles]/D");
    tree->Branch("gen_particle_mass", gen_particle_mass, "gen_particle_mass[num_gen_particles]/D");
    tree->Branch("gen_particle_charge", gen_particle_charge, "gen_particle_charge[num_gen_particles]/I");
    tree->Branch("gen_particle_id", gen_particle_id, "gen_particle_id[num_gen_particles]/I");
    tree->Branch("gen_particle_status", gen_particle_status, "gen_particle_status[num_gen_particles]/I");
    tree->Branch("gen_particle_mother", gen_particle_mother, "gen_particle_mother[num_gen_particles]/I");
    tree->Branch("gen_particle_fromHardProcessFinalState", gen_particle_fromHardProcessFinalState, "gen_particle_fromHardProcessFinalState[num_gen_particles]/O");
    tree->Branch("gen_particle_fromHardProcessDecayed", gen_particle_fromHardProcessDecayed, "gen_particle_fromHardProcessDecayed[num_gen_particles]/O");
    tree->Branch("gen_particle_fromHardProcessBeforeFSR", gen_particle_fromHardProcessBeforeFSR, "gen_particle_fromHardProcessBeforeFSR[num_gen_particles]/O");
    tree->Branch("gen_particle_isHardProcess", gen_particle_isHardProcess, "gen_particle_isHardProcess[num_gen_particles]/O");
    tree->Branch("gen_particle_isLastCopy", gen_particle_isLastCopy, "gen_particle_isLastCopy[num_gen_particles]/O");
    tree->Branch("gen_particle_isLastCopyBeforeFSR", gen_particle_isLastCopyBeforeFSR, "gen_particle_isLastCopyBeforeFSR[num_gen_particles]/O");
    tree->Branch("gen_particle_isPromptDecayed", gen_particle_isPromptDecayed, "gen_particle_isPromptDecayed[num_gen_particles]/O");
    tree->Branch("gen_particle_isPromptFinalState", gen_particle_isPromptFinalState, "gen_particle_isPromptFinalState[num_gen_particles]/O");
    tree->Branch("gen_particle_isDirectHardProcessTauDecayProductFinalState", gen_particle_isDirectHardProcessTauDecayProductFinalState, "gen_particle_isDirectHardProcessTauDecayProductFinalState[num_gen_particles]/O");
    tree->Branch("gen_particle_isDirectPromptTauDecayProductFinalState", gen_particle_isDirectPromptTauDecayProductFinalState, "gen_particle_isDirectPromptTauDecayProductFinalState[num_gen_particles]/O");

    // tree->Branch("num_jets", &num_jets);
    // tree->Branch("jet_pt", jet_pt, "jet_pt[num_jets]/D");
    // tree->Branch("jet_eta", jet_eta, "jet_eta[num_jets]/D");
    // tree->Branch("jet_phi", jet_phi, "jet_phi[num_jets]/D");
    // tree->Branch("jet_charge", jet_charge, "jet_charge[num_jets]/D");
    // tree->Branch("jet_flavor", jet_flavor, "jet_flavor[num_jets]/I");
    // tree->Branch("jet_bTag", jet_bTag, "jet_bTag[num_jets]/D");
    // tree->Branch("jet_CHF", jet_CHF, "jet_CHF[num_jets]/D");
    // tree->Branch("jet_NHF", jet_NHF, "jet_NHF[num_jets]/D");
    // tree->Branch("jet_CEMF", jet_CEMF, "jet_CEMF[num_jets]/D");
    // tree->Branch("jet_NEMF", jet_NEMF, "jet_NEMF[num_jets]/D");
    // tree->Branch("jet_CHM", jet_CHM, "jet_CHM[num_jets]/I");
    // tree->Branch("jet_NHM", jet_NHM, "jet_NHM[num_jets]/I");
    // tree->Branch("jet_MUF", jet_MUF, "jet_MUF[num_jets]/D");

    tree->Branch("num_protons", &num_protons);
    tree->Branch("proton_xi", proton_xi, "proton_xi[num_protons]/D");
    tree->Branch("proton_method", proton_method, "proton_method[num_protons]/I");
    tree->Branch("proton_lhcSector", proton_lhcSector, "proton_lhcSector[num_protons]/I");
    tree->Branch("proton_isValid", proton_isValid, "proton_isValid[num_protons]/O");

    tree->Branch("num_local_tracks", &num_local_tracks);
    tree->Branch("local_track_rpId", local_track_rpId, "local_track_rpId[num_local_tracks]/I");
    tree->Branch("local_track_x", local_track_x, "local_track_x[num_local_tracks]/D");
    tree->Branch("local_track_x_unc", local_track_x_unc, "local_track_x_unc[num_local_tracks]/D");
    tree->Branch("local_track_y", local_track_y, "local_track_y[num_local_tracks]/D");
    tree->Branch("local_track_y_unc", local_track_y_unc, "local_track_y_unc[num_local_tracks]/D");
    tree->Branch("local_track_tx", local_track_tx, "local_track_tx[num_local_tracks]/D");
    tree->Branch("local_track_tx_unc", local_track_tx_unc, "local_track_tx_unc[num_local_tracks]/D");
    tree->Branch("local_track_ty", local_track_ty, "local_track_ty[num_local_tracks]/D");
    tree->Branch("local_track_ty_unc", local_track_ty_unc, "local_track_ty_unc[num_local_tracks]/D");
    tree->Branch("local_track_chiSquaredOverNDF", local_track_chiSquaredOverNDF, "local_track_chiSquaredOverNDF[num_local_tracks]/D");
}

void EventBuffer::SetBranchRead(TChain* tree)
{
    tree->SetBranchAddress("run", &run);
    tree->SetBranchAddress("ls", &ls);
    tree->SetBranchAddress("event", &event);
    tree->SetBranchAddress("num_vertices", &num_vertices);
    tree->SetBranchAddress("rho", &rho);
    tree->SetBranchAddress("num_pu", &num_pu);
    tree->SetBranchAddress("num_pu_in_time", &num_pu_in_time);
    tree->SetBranchAddress("weight", &weight);

    tree->SetBranchAddress("num_filters", &num_filters);
    tree->SetBranchAddress("filter_name", &filter_name);
    tree->SetBranchAddress("filter_decision", filter_decision);

    tree->SetBranchAddress("num_triggers", &num_triggers);
    tree->SetBranchAddress("trigger_name", &trigger_name);
    tree->SetBranchAddress("trigger_decision", trigger_decision);

    tree->SetBranchAddress("num_electrons", &num_electrons);
    tree->SetBranchAddress("electron_pt", electron_pt);
    tree->SetBranchAddress("electron_corrected_pt", electron_corrected_pt);
    tree->SetBranchAddress("electron_eta", electron_eta);
    tree->SetBranchAddress("electron_phi", electron_phi);
    tree->SetBranchAddress("electron_sc_eta", electron_sc_eta);
    tree->SetBranchAddress("electron_sc_phi", electron_sc_phi);
    
    tree->SetBranchAddress("electron_charge", electron_charge);
    tree->SetBranchAddress("electron_pass_cutbased_veto", electron_pass_cutbased_veto);
    tree->SetBranchAddress("electron_pass_cutbased_loose", electron_pass_cutbased_loose);
    tree->SetBranchAddress("electron_pass_cutbased_medium", electron_pass_cutbased_medium);
    tree->SetBranchAddress("electron_pass_cutbased_tight", electron_pass_cutbased_tight);
    tree->SetBranchAddress("electron_pass_cutbased_heep", electron_pass_cutbased_heep);
    tree->SetBranchAddress("electron_pass_mva_wp80", electron_pass_mva_wp80);
    tree->SetBranchAddress("electron_pass_mva_wp90", electron_pass_mva_wp90);
    tree->SetBranchAddress("electron_mva_value", electron_mva_value);
    tree->SetBranchAddress("electron_mva_category", electron_mva_category);


    tree->SetBranchAddress("electron_sigmaIetaIeta", electron_sigmaIetaIeta);
    tree->SetBranchAddress("electron_E1x5", electron_E1x5);
    tree->SetBranchAddress("electron_E2x5", electron_E2x5);
    tree->SetBranchAddress("electron_E5x5", electron_E5x5);
    tree->SetBranchAddress("electron_hOverE", electron_hOverE);
    tree->SetBranchAddress("electron_dEtaInSeed", electron_dEtaInSeed);
    tree->SetBranchAddress("electron_dPhiIn", electron_dPhiIn);
    tree->SetBranchAddress("electron_ooEmooP", electron_ooEmooP);
    tree->SetBranchAddress("electron_d0", electron_d0);
    tree->SetBranchAddress("electron_expectedMissingInnerHits", electron_expectedMissingInnerHits);
    tree->SetBranchAddress("electron_passConversionVeto", electron_passConversionVeto);

    tree->SetBranchAddress("electron_isoChargedHadrons", electron_isoChargedHadrons);
    tree->SetBranchAddress("electron_isoNeutralHadrons", electron_isoNeutralHadrons);
    tree->SetBranchAddress("electron_isoPhotons", electron_isoPhotons);
    tree->SetBranchAddress("electron_isoChargedFromPU", electron_isoChargedFromPU);
    tree->SetBranchAddress("electron_isoDeltaBeta", electron_isoDeltaBeta);
    tree->SetBranchAddress("electron_isoRho", electron_isoRho);
    tree->SetBranchAddress("electron_dr03ecalRecHitSumEt", electron_dr03ecalRecHitSumEt);
    tree->SetBranchAddress("electron_dr03hcalDepth1TowerSumEt", electron_dr03hcalDepth1TowerSumEt);
    tree->SetBranchAddress("electron_dr03hcalDepth1TowerSumEtBc", electron_dr03hcalDepth1TowerSumEtBc);
    tree->SetBranchAddress("electron_dr03hcalDepth2TowerSumEt", electron_dr03hcalDepth2TowerSumEt);
    tree->SetBranchAddress("electron_dr03hcalDepth2TowerSumEtBc", electron_dr03hcalDepth2TowerSumEtBc);
    tree->SetBranchAddress("electron_dr03tkSumPt", electron_dr03tkSumPt);
    tree->SetBranchAddress("electron_dr04ecalRecHitSumEt", electron_dr04ecalRecHitSumEt);
    tree->SetBranchAddress("electron_dr04hcalDepth1TowerSumEt", electron_dr04hcalDepth1TowerSumEt);
    tree->SetBranchAddress("electron_dr04hcalDepth1TowerSumEtBc", electron_dr04hcalDepth1TowerSumEtBc);
    tree->SetBranchAddress("electron_dr04hcalDepth2TowerSumEt", electron_dr04hcalDepth2TowerSumEt);
    tree->SetBranchAddress("electron_dr04hcalDepth1TowerSumEtBc", electron_dr04hcalDepth1TowerSumEtBc);
    tree->SetBranchAddress("electron_dr04tkSumPt", electron_dr04tkSumPt);
    
    tree->SetBranchAddress("electron_miniiso_ea", electron_miniiso_ea);
    tree->SetBranchAddress("electron_miniiso_dbeta", electron_miniiso_dbeta);
    
    tree->SetBranchAddress("electron_gain", electron_gain);
    tree->SetBranchAddress("electron_r9", electron_r9);

    tree->SetBranchAddress("num_muons", &num_muons);
    tree->SetBranchAddress("muon_isGlobalMuon", muon_isGlobalMuon);
    tree->SetBranchAddress("muon_isStandAloneMuon", muon_isStandAloneMuon);
    tree->SetBranchAddress("muon_isTrackerMuon", muon_isTrackerMuon);
    tree->SetBranchAddress("muon_isPFMuon", muon_isPFMuon);

    tree->SetBranchAddress("muon_pt", muon_pt);
    tree->SetBranchAddress("muon_corrected_pt", muon_corrected_pt);
    tree->SetBranchAddress("muon_eta", muon_eta);
    tree->SetBranchAddress("muon_phi", muon_phi);
    tree->SetBranchAddress("muon_charge", muon_charge);

    tree->SetBranchAddress("muon_numberOfChambers", muon_numberOfChambers);
    tree->SetBranchAddress("muon_stationMask", muon_stationMask);
    tree->SetBranchAddress("muon_numberOfMatchedStations", muon_numberOfMatchedStations);

    tree->SetBranchAddress("muon_global_pt", muon_global_pt);
    tree->SetBranchAddress("muon_global_ptError", muon_global_ptError);
    tree->SetBranchAddress("muon_global_phi", muon_global_phi);
    tree->SetBranchAddress("muon_global_eta", muon_global_eta);
    tree->SetBranchAddress("muon_global_normalizedChi2", muon_global_normalizedChi2);
    tree->SetBranchAddress("muon_global_numberOfValidPixelHits", muon_global_numberOfValidPixelHits);
    tree->SetBranchAddress("muon_global_numberOfValidMuonHits", muon_global_numberOfValidMuonHits);
    tree->SetBranchAddress("muon_global_trackerLayersWithMeasurement", muon_global_trackerLayersWithMeasurement);
    tree->SetBranchAddress("muon_global_dxy_vtx", muon_global_dxy_vtx);
    tree->SetBranchAddress("muon_global_dz_vtx", muon_global_dz_vtx);
    tree->SetBranchAddress("muon_global_validFraction", muon_global_validFraction);

    tree->SetBranchAddress("muon_inner_pt", muon_inner_pt);
    tree->SetBranchAddress("muon_inner_ptError", muon_inner_ptError);
    tree->SetBranchAddress("muon_inner_phi", muon_inner_phi);
    tree->SetBranchAddress("muon_inner_eta", muon_inner_eta);
    tree->SetBranchAddress("muon_inner_normalizedChi2", muon_inner_normalizedChi2);
    tree->SetBranchAddress("muon_inner_numberOfValidPixelHits", muon_inner_numberOfValidPixelHits);
    tree->SetBranchAddress("muon_inner_numberOfValidMuonHits", muon_inner_numberOfValidMuonHits);
    tree->SetBranchAddress("muon_inner_trackerLayersWithMeasurement", muon_inner_trackerLayersWithMeasurement);
    tree->SetBranchAddress("muon_inner_dxy_vtx", muon_inner_dxy_vtx);
    tree->SetBranchAddress("muon_inner_dz_vtx", muon_inner_dz_vtx);
    tree->SetBranchAddress("muon_inner_validFraction", muon_inner_validFraction);

    tree->SetBranchAddress("muon_outer_pt", muon_outer_pt);
    tree->SetBranchAddress("muon_outer_ptError", muon_outer_ptError);
    tree->SetBranchAddress("muon_outer_phi", muon_outer_phi);
    tree->SetBranchAddress("muon_outer_eta", muon_outer_eta);
    tree->SetBranchAddress("muon_outer_normalizedChi2", muon_outer_normalizedChi2);
    tree->SetBranchAddress("muon_outer_numberOfValidPixelHits", muon_outer_numberOfValidPixelHits);
    tree->SetBranchAddress("muon_outer_numberOfValidMuonHits", muon_outer_numberOfValidMuonHits);
    tree->SetBranchAddress("muon_outer_trackerLayersWithMeasurement", muon_outer_trackerLayersWithMeasurement);
    tree->SetBranchAddress("muon_outer_dxy_vtx", muon_outer_dxy_vtx);
    tree->SetBranchAddress("muon_outer_dz_vtx", muon_outer_dz_vtx);
    tree->SetBranchAddress("muon_outer_validFraction", muon_outer_validFraction);

    tree->SetBranchAddress("muon_best_pt", muon_best_pt);
    tree->SetBranchAddress("muon_best_ptError", muon_best_ptError);
    tree->SetBranchAddress("muon_best_phi", muon_best_phi);
    tree->SetBranchAddress("muon_best_eta", muon_best_eta);
    tree->SetBranchAddress("muon_best_normalizedChi2", muon_best_normalizedChi2);
    tree->SetBranchAddress("muon_best_numberOfValidPixelHits", muon_best_numberOfValidPixelHits);
    tree->SetBranchAddress("muon_best_numberOfValidMuonHits", muon_best_numberOfValidMuonHits);
    tree->SetBranchAddress("muon_best_trackerLayersWithMeasurement", muon_best_trackerLayersWithMeasurement);
    tree->SetBranchAddress("muon_best_dxy_vtx", muon_best_dxy_vtx);
    tree->SetBranchAddress("muon_best_dz_vtx", muon_best_dz_vtx);
    tree->SetBranchAddress("muon_best_validFraction", muon_best_validFraction);

    tree->SetBranchAddress("muon_tunep_pt", muon_tunep_pt);
    tree->SetBranchAddress("muon_tunep_ptError", muon_tunep_ptError);
    tree->SetBranchAddress("muon_tunep_phi", muon_tunep_phi);
    tree->SetBranchAddress("muon_tunep_eta", muon_tunep_eta);
    tree->SetBranchAddress("muon_tunep_normalizedChi2", muon_tunep_normalizedChi2);
    tree->SetBranchAddress("muon_tunep_numberOfValidPixelHits", muon_tunep_numberOfValidPixelHits);
    tree->SetBranchAddress("muon_tunep_numberOfValidMuonHits", muon_tunep_numberOfValidMuonHits);
    tree->SetBranchAddress("muon_tunep_trackerLayersWithMeasurement", muon_tunep_trackerLayersWithMeasurement);
    tree->SetBranchAddress("muon_tunep_dxy_vtx", muon_tunep_dxy_vtx);
    tree->SetBranchAddress("muon_tunep_dz_vtx", muon_tunep_dz_vtx);
    tree->SetBranchAddress("muon_tunep_validFraction", muon_tunep_validFraction);

    tree->SetBranchAddress("muon_isolationR03_sumpt", muon_isolationR03_sumpt);
    tree->SetBranchAddress("muon_isolationR03_hadEt", muon_isolationR03_hadEt);
    tree->SetBranchAddress("muon_isolationR03_emEt", muon_isolationR03_emEt);
    tree->SetBranchAddress("muon_pfIsolationR04_sumPUPt", muon_pfIsolationR04_sumPUPt);
    tree->SetBranchAddress("muon_pfIsolationR04_sumPhotonEt", muon_pfIsolationR04_sumPhotonEt);
    tree->SetBranchAddress("muon_pfIsolationR04_sumChargedHadronPt", muon_pfIsolationR04_sumChargedHadronPt);
    tree->SetBranchAddress("muon_pfIsolationR04_sumNeutralHadronEt", muon_pfIsolationR04_sumNeutralHadronEt);
    tree->SetBranchAddress("muon_miniiso_ea", muon_miniiso_ea);
    tree->SetBranchAddress("muon_miniiso_dbeta", muon_miniiso_dbeta);
    tree->SetBranchAddress("muon_segmentCompatibility", muon_segmentCompatibility);
    tree->SetBranchAddress("muon_quality_trkKink", muon_quality_trkKink);
    tree->SetBranchAddress("muon_quality_chi2LocalPosition", muon_quality_chi2LocalPosition);

    tree->SetBranchAddress("num_photons", &num_photons);
    tree->SetBranchAddress("photon_pt", photon_pt);
    tree->SetBranchAddress("photon_corrected_pt", photon_corrected_pt);
    tree->SetBranchAddress("photon_eta", photon_eta);
    tree->SetBranchAddress("photon_phi", photon_phi);
    tree->SetBranchAddress("photon_sc_eta", photon_sc_eta);
    tree->SetBranchAddress("photon_sc_phi", photon_sc_phi);
    tree->SetBranchAddress("photon_has_pixel_seed", photon_has_pixel_seed);
    tree->SetBranchAddress("photon_pass_conversion_veto", photon_pass_conversion_veto);
    tree->SetBranchAddress("photon_pass_cutbased_loose", photon_pass_cutbased_loose);
    tree->SetBranchAddress("photon_pass_cutbased_medium", photon_pass_cutbased_medium);
    tree->SetBranchAddress("photon_pass_cutbased_tight", photon_pass_cutbased_tight);
    tree->SetBranchAddress("photon_mva_value", photon_mva_value);
    tree->SetBranchAddress("photon_mva_category", photon_mva_category);
    tree->SetBranchAddress("photon_pass_mva_wp80", photon_pass_mva_wp80);
    tree->SetBranchAddress("photon_pass_mva_wp90", photon_pass_mva_wp90);
    tree->SetBranchAddress("photon_HoverE", photon_HoverE);
    tree->SetBranchAddress("photon_Full5x5_SigmaIEtaIEta", photon_Full5x5_SigmaIEtaIEta);
    tree->SetBranchAddress("photon_ChIso", photon_ChIso);
    tree->SetBranchAddress("photon_NhIso", photon_NhIso);
    tree->SetBranchAddress("photon_PhIso", photon_PhIso);
    tree->SetBranchAddress("photon_ChIsoEa", photon_ChIsoEa);
    tree->SetBranchAddress("photon_NhIsoEa", photon_NhIsoEa);
    tree->SetBranchAddress("photon_PhIsoEa", photon_PhIsoEa);
    tree->SetBranchAddress("photon_gain", photon_gain);
    tree->SetBranchAddress("photon_r9", photon_r9);

    // tree->SetBranchAddress("num_jets", &num_jets);
    // tree->SetBranchAddress("jet_pt", jet_pt);
    // tree->SetBranchAddress("jet_eta", jet_eta);
    // tree->SetBranchAddress("jet_phi", jet_phi);
    // tree->SetBranchAddress("jet_charge", jet_charge);
    // tree->SetBranchAddress("jet_flavor", jet_flavor);
    // tree->SetBranchAddress("jet_bTag", jet_bTag);
    // tree->SetBranchAddress("jet_CHF", jet_CHF);
    // tree->SetBranchAddress("jet_NHF", jet_NHF);
    // tree->SetBranchAddress("jet_CEMF", jet_CEMF);
    // tree->SetBranchAddress("jet_NEMF", jet_NEMF);
    // tree->SetBranchAddress("jet_CHM", jet_CHM);
    // tree->SetBranchAddress("jet_NHM", jet_NHM);
    // tree->SetBranchAddress("jet_MUF", jet_MUF);

    tree->SetBranchAddress("num_gen_particles", &num_gen_particles);
    tree->SetBranchAddress("gen_particle_pt", gen_particle_pt);
    tree->SetBranchAddress("gen_particle_eta", gen_particle_eta);
    tree->SetBranchAddress("gen_particle_phi", gen_particle_phi);
    tree->SetBranchAddress("gen_particle_energy", gen_particle_energy);
    tree->SetBranchAddress("gen_particle_mass", gen_particle_mass);
    tree->SetBranchAddress("gen_particle_charge", gen_particle_charge);
    tree->SetBranchAddress("gen_particle_id", gen_particle_id);
    tree->SetBranchAddress("gen_particle_status", gen_particle_status);
    tree->SetBranchAddress("gen_particle_mother", gen_particle_mother);
    tree->SetBranchAddress("gen_particle_fromHardProcessFinalState", gen_particle_fromHardProcessFinalState);
    tree->SetBranchAddress("gen_particle_fromHardProcessDecayed", gen_particle_fromHardProcessDecayed);
    tree->SetBranchAddress("gen_particle_fromHardProcessBeforeFSR", gen_particle_fromHardProcessBeforeFSR);
    tree->SetBranchAddress("gen_particle_isHardProcess", gen_particle_isHardProcess);
    tree->SetBranchAddress("gen_particle_isLastCopy", gen_particle_isLastCopy);
    tree->SetBranchAddress("gen_particle_isLastCopyBeforeFSR", gen_particle_isLastCopyBeforeFSR);
    tree->SetBranchAddress("gen_particle_isPromptDecayed", gen_particle_isPromptDecayed);
    tree->SetBranchAddress("gen_particle_isPromptFinalState", gen_particle_isPromptFinalState);
    tree->SetBranchAddress("gen_particle_isDirectHardProcessTauDecayProductFinalState", gen_particle_isDirectHardProcessTauDecayProductFinalState);
    tree->SetBranchAddress("gen_particle_isDirectPromptTauDecayProductFinalState", gen_particle_isDirectPromptTauDecayProductFinalState);

    tree->SetBranchAddress("num_protons", &num_protons);
    tree->SetBranchAddress("proton_xi", proton_xi);
    tree->SetBranchAddress("proton_method", proton_method);
    tree->SetBranchAddress("proton_lhcSector", proton_lhcSector);
    tree->SetBranchAddress("proton_isValid", proton_isValid);

    tree->SetBranchAddress("num_local_tracks", &num_local_tracks);
    tree->SetBranchAddress("local_track_rpId", local_track_rpId);
    tree->SetBranchAddress("local_track_x", local_track_x);
    tree->SetBranchAddress("local_track_x_unc", local_track_x_unc);
    tree->SetBranchAddress("local_track_y", local_track_y);
    tree->SetBranchAddress("local_track_y_unc", local_track_y_unc);
    tree->SetBranchAddress("local_track_tx", local_track_tx);
    tree->SetBranchAddress("local_track_tx_unc", local_track_tx_unc);
    tree->SetBranchAddress("local_track_ty", local_track_ty);
    tree->SetBranchAddress("local_track_ty_unc", local_track_ty_unc);
    tree->SetBranchAddress("local_track_chiSquaredOverNDF", local_track_chiSquaredOverNDF);
}
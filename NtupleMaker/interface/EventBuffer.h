#ifndef _EVENTBUFFER_
#define _EVENTBUFFER_

#include "TChain.h"
#include "TTree.h"

class EventBuffer
{
public:
    static constexpr int MAX_SIZE = 1000;
    EventBuffer(): filter_name{new std::vector<std::string>()}, trigger_name{new std::vector<std::string>()} {};
    void Initialize();
    void SetBranchWrite(TTree*);
    void SetBranchRead(TChain*);

    int run;
    int ls;
    unsigned long long event;
    int num_vertices;
    double rho;
    int num_pu;
    int num_pu_in_time;
    double weight;

    int num_filters;
    std::vector<std::string>* filter_name;
    bool filter_decision[MAX_SIZE];

    int num_triggers;
    std::vector<std::string>* trigger_name;
    bool trigger_decision[MAX_SIZE];

    int num_electrons;

    double electron_pt[MAX_SIZE];
    double electron_corrected_pt[MAX_SIZE];
    double electron_eta[MAX_SIZE];
    double electron_phi[MAX_SIZE];
    double electron_sc_eta[MAX_SIZE];
    double electron_sc_phi[MAX_SIZE];
    int electron_charge[MAX_SIZE];
    bool electron_pass_cutbased_veto[MAX_SIZE];
    bool electron_pass_cutbased_loose[MAX_SIZE];
    bool electron_pass_cutbased_medium[MAX_SIZE];
    bool electron_pass_cutbased_tight[MAX_SIZE];
    bool electron_pass_cutbased_heep[MAX_SIZE];
    double electron_mva_value[MAX_SIZE];
    int electron_mva_category[MAX_SIZE];
    bool electron_pass_mva_wp80[MAX_SIZE];
    bool electron_pass_mva_wp90[MAX_SIZE];

    double electron_sigmaIetaIeta[MAX_SIZE];
    double electron_E1x5[MAX_SIZE];
    double electron_E2x5[MAX_SIZE];
    double electron_E5x5[MAX_SIZE];
    double electron_hOverE[MAX_SIZE];
    double electron_dEtaInSeed[MAX_SIZE];
    double electron_dPhiIn[MAX_SIZE];
    double electron_ooEmooP[MAX_SIZE];
    double electron_d0[MAX_SIZE];
    int electron_expectedMissingInnerHits[MAX_SIZE];
    bool electron_passConversionVeto[MAX_SIZE];

    double electron_isoChargedHadrons[MAX_SIZE];
    double electron_isoNeutralHadrons[MAX_SIZE];
    double electron_isoPhotons[MAX_SIZE];
    double electron_isoChargedFromPU[MAX_SIZE];
    double electron_isoDeltaBeta[MAX_SIZE];
    double electron_isoRho[MAX_SIZE];

    double electron_dr03ecalRecHitSumEt[MAX_SIZE];
    double electron_dr03hcalDepth1TowerSumEt[MAX_SIZE];
    double electron_dr03hcalDepth1TowerSumEtBc[MAX_SIZE];
    double electron_dr03hcalDepth2TowerSumEt[MAX_SIZE];
    double electron_dr03hcalDepth2TowerSumEtBc[MAX_SIZE];
    double electron_dr03tkSumPt[MAX_SIZE];

    double electron_dr04ecalRecHitSumEt[MAX_SIZE];
    double electron_dr04hcalDepth1TowerSumEt[MAX_SIZE];
    double electron_dr04hcalDepth1TowerSumEtBc[MAX_SIZE];
    double electron_dr04hcalDepth2TowerSumEt[MAX_SIZE];
    double electron_dr04hcalDepth2TowerSumEtBc[MAX_SIZE];
    double electron_dr04tkSumPt[MAX_SIZE];

    double electron_miniiso_ea[MAX_SIZE];
    double electron_miniiso_dbeta[MAX_SIZE];

    int electron_gain[MAX_SIZE];
    double electron_r9[MAX_SIZE];

    int num_muons;
    bool muon_isGlobalMuon[MAX_SIZE];
    bool muon_isStandAloneMuon[MAX_SIZE];
    bool muon_isTrackerMuon[MAX_SIZE];
    bool muon_isPFMuon[MAX_SIZE];

    double muon_pt[MAX_SIZE];
    double muon_corrected_pt[MAX_SIZE];
    double muon_phi[MAX_SIZE];
    double muon_eta[MAX_SIZE];
    int muon_charge[MAX_SIZE];

    int muon_numberOfChambers[MAX_SIZE];
    int muon_stationMask[MAX_SIZE];
    int muon_numberOfMatchedStations[MAX_SIZE];

    double muon_global_pt[MAX_SIZE];
    double muon_global_ptError[MAX_SIZE];
    double muon_global_phi[MAX_SIZE];
    double muon_global_eta[MAX_SIZE];
    double muon_global_normalizedChi2[MAX_SIZE];
    int muon_global_numberOfValidPixelHits[MAX_SIZE];
    int muon_global_trackerLayersWithMeasurement[MAX_SIZE];
    int muon_global_numberOfValidMuonHits[MAX_SIZE];
    double muon_global_dxy_vtx[MAX_SIZE];
    double muon_global_dz_vtx[MAX_SIZE];
    double muon_global_validFraction[MAX_SIZE];

    double muon_inner_pt[MAX_SIZE];
    double muon_inner_ptError[MAX_SIZE];
    double muon_inner_phi[MAX_SIZE];
    double muon_inner_eta[MAX_SIZE];
    double muon_inner_normalizedChi2[MAX_SIZE];
    int muon_inner_numberOfValidPixelHits[MAX_SIZE];
    int muon_inner_trackerLayersWithMeasurement[MAX_SIZE];
    int muon_inner_numberOfValidMuonHits[MAX_SIZE];
    double muon_inner_dxy_vtx[MAX_SIZE];
    double muon_inner_dz_vtx[MAX_SIZE];
    double muon_inner_validFraction[MAX_SIZE];

    double muon_outer_pt[MAX_SIZE];
    double muon_outer_ptError[MAX_SIZE];
    double muon_outer_phi[MAX_SIZE];
    double muon_outer_eta[MAX_SIZE];
    double muon_outer_normalizedChi2[MAX_SIZE];
    int muon_outer_numberOfValidPixelHits[MAX_SIZE];
    int muon_outer_trackerLayersWithMeasurement[MAX_SIZE];
    int muon_outer_numberOfValidMuonHits[MAX_SIZE];
    double muon_outer_dxy_vtx[MAX_SIZE];
    double muon_outer_dz_vtx[MAX_SIZE];
    double muon_outer_validFraction[MAX_SIZE];

    double muon_best_pt[MAX_SIZE];
    double muon_best_ptError[MAX_SIZE];
    double muon_best_phi[MAX_SIZE];
    double muon_best_eta[MAX_SIZE];
    double muon_best_normalizedChi2[MAX_SIZE];
    int muon_best_numberOfValidPixelHits[MAX_SIZE];
    int muon_best_trackerLayersWithMeasurement[MAX_SIZE];
    int muon_best_numberOfValidMuonHits[MAX_SIZE];
    double muon_best_dxy_vtx[MAX_SIZE];
    double muon_best_dz_vtx[MAX_SIZE];
    double muon_best_validFraction[MAX_SIZE];

    double muon_tunep_pt[MAX_SIZE];
    double muon_tunep_ptError[MAX_SIZE];
    double muon_tunep_phi[MAX_SIZE];
    double muon_tunep_eta[MAX_SIZE];
    double muon_tunep_normalizedChi2[MAX_SIZE];
    int muon_tunep_numberOfValidPixelHits[MAX_SIZE];
    int muon_tunep_trackerLayersWithMeasurement[MAX_SIZE];
    int muon_tunep_numberOfValidMuonHits[MAX_SIZE];
    double muon_tunep_dxy_vtx[MAX_SIZE];
    double muon_tunep_dz_vtx[MAX_SIZE];
    double muon_tunep_validFraction[MAX_SIZE];

    double muon_isolationR03_sumpt[MAX_SIZE];
    double muon_isolationR03_hadEt[MAX_SIZE];
    double muon_isolationR03_emEt[MAX_SIZE];
    double muon_pfIsolationR04_sumChargedHadronPt[MAX_SIZE];
    double muon_pfIsolationR04_sumNeutralHadronEt[MAX_SIZE];
    double muon_pfIsolationR04_sumPhotonEt[MAX_SIZE];
    double muon_pfIsolationR04_sumPUPt[MAX_SIZE];
    double muon_miniiso_ea[MAX_SIZE];
    double muon_miniiso_dbeta[MAX_SIZE];

    double muon_segmentCompatibility[MAX_SIZE];
    double muon_quality_chi2LocalPosition[MAX_SIZE];
    double muon_quality_trkKink[MAX_SIZE];

    int num_photons;
    double photon_pt[MAX_SIZE];
    double photon_corrected_pt[MAX_SIZE];
    double photon_eta[MAX_SIZE];
    double photon_phi[MAX_SIZE];
    double photon_sc_eta[MAX_SIZE];
    double photon_sc_phi[MAX_SIZE];
    bool photon_has_pixel_seed[MAX_SIZE];
    bool photon_pass_conversion_veto[MAX_SIZE];
    bool photon_pass_cutbased_loose[MAX_SIZE];
    bool photon_pass_cutbased_medium[MAX_SIZE];
    bool photon_pass_cutbased_tight[MAX_SIZE];
    double photon_mva_value[MAX_SIZE];
    int photon_mva_category[MAX_SIZE];
    bool photon_pass_mva_wp80[MAX_SIZE];
    bool photon_pass_mva_wp90[MAX_SIZE];
    double photon_HoverE[MAX_SIZE];
    double photon_Full5x5_SigmaIEtaIEta[MAX_SIZE];
    double photon_ChIso[MAX_SIZE];
    double photon_NhIso[MAX_SIZE];
    double photon_PhIso[MAX_SIZE];
    double photon_ChIsoEa[MAX_SIZE];
    double photon_NhIsoEa[MAX_SIZE];
    double photon_PhIsoEa[MAX_SIZE];
    int photon_gain[MAX_SIZE];
    double photon_r9[MAX_SIZE];

    int num_gen_particles;
    double gen_particle_pt[MAX_SIZE];
    double gen_particle_eta[MAX_SIZE];
    double gen_particle_phi[MAX_SIZE];
    double gen_particle_energy[MAX_SIZE];
    double gen_particle_mass[MAX_SIZE];
    int gen_particle_charge[MAX_SIZE];
    int gen_particle_id[MAX_SIZE];
    int gen_particle_status[MAX_SIZE];
    int gen_particle_mother[MAX_SIZE];
    bool gen_particle_fromHardProcessFinalState[MAX_SIZE];
    bool gen_particle_fromHardProcessDecayed[MAX_SIZE];
    bool gen_particle_fromHardProcessBeforeFSR[MAX_SIZE];
    bool gen_particle_isHardProcess[MAX_SIZE];
    bool gen_particle_isLastCopy[MAX_SIZE];
    bool gen_particle_isLastCopyBeforeFSR[MAX_SIZE];
    bool gen_particle_isPromptDecayed[MAX_SIZE];
    bool gen_particle_isPromptFinalState[MAX_SIZE];
    bool gen_particle_isDirectHardProcessTauDecayProductFinalState[MAX_SIZE];
    bool gen_particle_isDirectPromptTauDecayProductFinalState[MAX_SIZE];

    int num_jets;
    double jet_pt[MAX_SIZE];
    double jet_eta[MAX_SIZE];
    double jet_phi[MAX_SIZE];
    double jet_charge[MAX_SIZE];
    int jet_flavor[MAX_SIZE];
    double jet_bTag[MAX_SIZE];
    double jet_CHF[MAX_SIZE];
    double jet_NHF[MAX_SIZE];
    double jet_NEMF[MAX_SIZE];
    double jet_CEMF[MAX_SIZE];
    int jet_CHM[MAX_SIZE];
    int jet_NHM[MAX_SIZE];
    double jet_MUF[MAX_SIZE];

    int num_protons;
    double proton_xi[MAX_SIZE];
    // double proton_xi_unc[MAX_SIZE];
    int proton_method[MAX_SIZE];
    int proton_lhcSector[MAX_SIZE];
    bool proton_isValid[MAX_SIZE];

    int num_local_tracks;
    int local_track_rpId[MAX_SIZE];
    double local_track_x[MAX_SIZE];
    double local_track_x_unc[MAX_SIZE];
    double local_track_y[MAX_SIZE];
    double local_track_y_unc[MAX_SIZE];
    double local_track_tx[MAX_SIZE];
    double local_track_tx_unc[MAX_SIZE];
    double local_track_ty[MAX_SIZE];
    double local_track_ty_unc[MAX_SIZE];
    double local_track_chiSquaredOverNDF[MAX_SIZE];
};

#endif
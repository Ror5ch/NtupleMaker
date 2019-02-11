#include "Physics/NtupleMaker/interface/NtupleMaker.h"

void NtupleMaker::FillWithMuons(const edm::Event& iEvent)
{
    edm::Handle<std::vector<pat::Muon>> muons;
    edm::Handle<pat::PackedCandidateCollection> pfcands;
    edm::Handle<double> rho_for_miniiso;
    iEvent.getByToken(muons_token_,muons);
    iEvent.getByToken(pfcandidates_token_, pfcands);
    iEvent.getByToken(rho_for_miniiso_token_,rho_for_miniiso);

    event_.num_muons = muons->size();
    if (muons->size() == 0) return;

    int i = 0;
    for (const auto& muon : *muons) 
    {    
        FillMuonVariables(muon, i);
        FillMuonGlobalTrackVariables(muon.globalTrack(), i); 
        FillMuonInnerTrackVariables(muon.innerTrack(), i); 
        FillMuonOuterTrackVariables(muon.outerTrack(), i); 
        FillMuonMuonBestTrackVariables(muon.muonBestTrack(), i); 
        FillMuonTunePTrackVariables(muon.tunePMuonBestTrack(), i); 
        FillMuonIsolationVariables(muon, pfcands, *rho_for_miniiso, i);
        i++;
    }
}
void NtupleMaker::FillMuonVariables(const pat::Muon& muon, const int& index)
{
    event_.muon_isStandAloneMuon[index] = muon.isStandAloneMuon();
    event_.muon_isGlobalMuon[index]     = muon.isGlobalMuon();
    event_.muon_isTrackerMuon[index]    = muon.isTrackerMuon();
    event_.muon_isPFMuon[index]         = muon.isPFMuon();

    event_.muon_pt[index]     = muon.pt();
    event_.muon_eta[index]    = muon.eta();
    event_.muon_phi[index]    = muon.phi();
    event_.muon_charge[index] = muon.charge();

    event_.muon_numberOfChambers[index]        = muon.numberOfChambers();
    event_.muon_stationMask[index]             = muon.stationMask();
    event_.muon_numberOfMatchedStations[index] = muon.numberOfMatchedStations();

    event_.muon_segmentCompatibility[index] = muon.segmentCompatibility();
    if (muon.isPFMuon()) 
    {
        event_.muon_quality_chi2LocalPosition[index] = muon.combinedQuality().chi2LocalPosition;
        event_.muon_quality_trkKink[index]           = muon.combinedQuality().trkKink;
    }
}
void NtupleMaker::FillMuonGlobalTrackVariables(const reco::TrackRef muon_track, const int& index)
{
    if (muon_track.isNonnull()) 
    {
        event_.muon_global_normalizedChi2[index]  = muon_track->normalizedChi2();
        event_.muon_global_numberOfValidPixelHits[index] = muon_track->hitPattern().numberOfValidPixelHits();
        event_.muon_global_trackerLayersWithMeasurement[index]  = muon_track->hitPattern().trackerLayersWithMeasurement();
        event_.muon_global_numberOfValidMuonHits[index]  = muon_track->hitPattern().numberOfValidMuonHits();

        event_.muon_global_pt[index]      = muon_track->pt();
        event_.muon_global_ptError[index] = muon_track->ptError();
        event_.muon_global_eta[index]     = muon_track->eta();
        event_.muon_global_phi[index]     = muon_track->phi();

        event_.muon_global_validFraction[index]  = muon_track->validFraction();

        if (!pvHandle->empty() && !pvHandle->front().isFake()) 
        {
            event_.muon_global_dxy_vtx[index] = muon_track->dxy(vtx.position());
            event_.muon_global_dz_vtx[index]  = muon_track->dz(vtx.position());
        }
    }
}
void NtupleMaker::FillMuonInnerTrackVariables(const reco::TrackRef muon_track, const int& index)
{
    if (muon_track.isNonnull()) 
    {
        event_.muon_inner_normalizedChi2[index]  = muon_track->normalizedChi2();
        event_.muon_inner_numberOfValidPixelHits[index] = muon_track->hitPattern().numberOfValidPixelHits();
        event_.muon_inner_trackerLayersWithMeasurement[index]  = muon_track->hitPattern().trackerLayersWithMeasurement();
        event_.muon_inner_numberOfValidMuonHits[index]  = muon_track->hitPattern().numberOfValidMuonHits();

        event_.muon_inner_pt[index]      = muon_track->pt();
        event_.muon_inner_ptError[index] = muon_track->ptError();
        event_.muon_inner_eta[index]     = muon_track->eta();
        event_.muon_inner_phi[index]     = muon_track->phi();

        event_.muon_inner_validFraction[index]  = muon_track->validFraction();

        if (!pvHandle->empty() && !pvHandle->front().isFake()) 
        {
            event_.muon_inner_dxy_vtx[index] = muon_track->dxy(vtx.position());
            event_.muon_inner_dz_vtx[index]  = muon_track->dz(vtx.position());
        }
    }
}
void NtupleMaker::FillMuonOuterTrackVariables(const reco::TrackRef muon_track, const int& index)
{
    if (muon_track.isNonnull()) 
    {
        event_.muon_outer_normalizedChi2[index]  = muon_track->normalizedChi2();
        event_.muon_outer_numberOfValidPixelHits[index] = muon_track->hitPattern().numberOfValidPixelHits();
        event_.muon_outer_trackerLayersWithMeasurement[index]  = muon_track->hitPattern().trackerLayersWithMeasurement();
        event_.muon_outer_numberOfValidMuonHits[index]  = muon_track->hitPattern().numberOfValidMuonHits();

        event_.muon_outer_pt[index]      = muon_track->pt();
        event_.muon_outer_ptError[index] = muon_track->ptError();
        event_.muon_outer_eta[index]     = muon_track->eta();
        event_.muon_outer_phi[index]     = muon_track->phi();

        event_.muon_outer_validFraction[index]  = muon_track->validFraction();

        if (!pvHandle->empty() && !pvHandle->front().isFake()) 
        {
            event_.muon_outer_dxy_vtx[index] = muon_track->dxy(vtx.position());
            event_.muon_outer_dz_vtx[index]  = muon_track->dz(vtx.position());
        }
    }
}
void NtupleMaker::FillMuonMuonBestTrackVariables(const reco::TrackRef muon_track, const int& index)
{
    if (muon_track.isNonnull()) 
    {
        event_.muon_best_normalizedChi2[index]  = muon_track->normalizedChi2();
        event_.muon_best_numberOfValidPixelHits[index] = muon_track->hitPattern().numberOfValidPixelHits();
        event_.muon_best_trackerLayersWithMeasurement[index]  = muon_track->hitPattern().trackerLayersWithMeasurement();
        event_.muon_best_numberOfValidMuonHits[index]  = muon_track->hitPattern().numberOfValidMuonHits();

        event_.muon_best_pt[index]      = muon_track->pt();
        event_.muon_best_ptError[index] = muon_track->ptError();
        event_.muon_best_eta[index]     = muon_track->eta();
        event_.muon_best_phi[index]     = muon_track->phi();

        event_.muon_best_validFraction[index]  = muon_track->validFraction();

        if (!pvHandle->empty() && !pvHandle->front().isFake()) 
        {
            event_.muon_best_dxy_vtx[index] = muon_track->dxy(vtx.position());
            event_.muon_best_dz_vtx[index]  = muon_track->dz(vtx.position());
        }
    }
}
void NtupleMaker::FillMuonTunePTrackVariables(const reco::TrackRef muon_track, const int& index)
{
    if (muon_track.isNonnull()) 
    {
        event_.muon_tunep_normalizedChi2[index]  = muon_track->normalizedChi2();
        event_.muon_tunep_numberOfValidPixelHits[index] = muon_track->hitPattern().numberOfValidPixelHits();
        event_.muon_tunep_trackerLayersWithMeasurement[index]  = muon_track->hitPattern().trackerLayersWithMeasurement();
        event_.muon_tunep_numberOfValidMuonHits[index]  = muon_track->hitPattern().numberOfValidMuonHits();

        event_.muon_tunep_pt[index]      = muon_track->pt();
        event_.muon_tunep_ptError[index] = muon_track->ptError();
        event_.muon_tunep_eta[index]     = muon_track->eta();
        event_.muon_tunep_phi[index]     = muon_track->phi();

        event_.muon_tunep_validFraction[index]  = muon_track->validFraction();

        if (!pvHandle->empty() && !pvHandle->front().isFake()) 
        {
            event_.muon_tunep_dxy_vtx[index] = muon_track->dxy(vtx.position());
            event_.muon_tunep_dz_vtx[index]  = muon_track->dz(vtx.position());
        }
    }
}
void NtupleMaker::FillMuonIsolationVariables(const pat::Muon& muon, const edm::Handle<pat::PackedCandidateCollection>& pfcands, const double& rho_for_miniiso, const int& index)
{
    event_.muon_isolationR03_sumpt[index] = muon.isolationR03().sumPt;
    event_.muon_isolationR03_hadEt[index] = muon.isolationR03().hadEt;
    event_.muon_isolationR03_emEt [index] = muon.isolationR03().emEt;

    event_.muon_pfIsolationR04_sumChargedHadronPt[index] = muon.pfIsolationR04().sumChargedHadronPt;
    event_.muon_pfIsolationR04_sumNeutralHadronEt[index] = muon.pfIsolationR04().sumNeutralHadronEt;
    event_.muon_pfIsolationR04_sumPhotonEt[index] = muon.pfIsolationR04().sumPhotonEt;
    event_.muon_pfIsolationR04_sumPUPt[index] = muon.pfIsolationR04().sumPUPt;

    event_.muon_miniiso_ea[index] = GetMiniIsolation(pfcands, dynamic_cast<const reco::Candidate *>(&muon), 0.05, 0.2, 10., rho_for_miniiso, true);
    event_.muon_miniiso_dbeta[index] = GetMiniIsolation(pfcands, dynamic_cast<const reco::Candidate *>(&muon), 0.05, 0.2, 10., rho_for_miniiso, false);
}

// -*- C++ -*-
//
// Package:    Physics/NtupleMaker
// Class:      NtupleMaker
// 
/**\class NtupleMaker NtupleMaker.cc Physics/NtupleMaker/plugins/NtupleMaker.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Kyungwook Nam
//         Created:  Sat, 23 Jan 2016 15:57:13 GMT
//
//

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h" 
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/MuonReco/interface/MuonFwd.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaCandidates/interface/ConversionFwd.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/HcalNoiseSummary.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "JetMETCorrections/Objects/interface/JetCorrectionsRecord.h"
#include "JetMETCorrections/Objects/interface/JetCorrector.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "MagneticField/Records/interface/IdealMagneticFieldRecord.h"
#include "PhysicsTools/RecoUtils/interface/CandCommonVertexFitter.h"
#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"
#include "RecoEgamma/EgammaTools/interface/EffectiveAreas.h"
#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"
#include "RecoVertex/VertexTools/interface/InvariantMassFromVertex.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/TransientTrack/interface/GsfTransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"

#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/PatCandidates/interface/VIDCutFlowResult.h"
#include "DataFormats/DetId/interface/DetIdCollection.h" // REMINIAOD

#include <TTree.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TFile.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TFrame.h>
#include <TMath.h>
#include <TF1.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <boost/foreach.hpp>
#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <cassert>
     
#include "LHAPDF/LHAPDF.h"
     
#include "Physics/NtupleMaker/interface/EventBuffer.h"

#ifndef NtupleMaker_H
#define NtupleMaker_H

using namespace std;
using namespace reco;
using namespace edm;
using namespace pat;
using namespace isodeposit;

//
// class declaration
//

class NtupleMaker : public edm::one::EDAnalyzer<edm::one::SharedResources>
{
public:
    explicit NtupleMaker(const edm::ParameterSet&);
    ~NtupleMaker();
    static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
    virtual void beginJob() override;
    virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
    virtual void endJob() override;

    void FillWithPileup(const edm::Event&);
    void FillWithTriggerResults(const edm::Event&);
    void FillWithFilters(const edm::Event&);
    void FillWithElectrons(const edm::Event&);
    void FillWithMuons(const edm::Event&);
    void FillMuonVariables(const pat::Muon&, const int& i);
    void FillMuonGlobalTrackVariables(const reco::TrackRef, const int& i);
    void FillMuonInnerTrackVariables(const reco::TrackRef, const int& i);
    void FillMuonOuterTrackVariables(const reco::TrackRef, const int& i);
    void FillMuonMuonBestTrackVariables(const reco::TrackRef, const int& i);
    void FillMuonTunePTrackVariables(const reco::TrackRef, const int& i);
    void FillMuonIsolationVariables(const pat::Muon&, const edm::Handle<pat::PackedCandidateCollection>&, const double&, const int& i);
    void FillWithPhotons(const edm::Event&);
    void FillWithGenparticles(const edm::Event&);
    void FillWithJets(const edm::Event&);

    double GetMiniIsolation(const edm::Handle<pat::PackedCandidateCollection>&, const reco::Candidate*, double, double, double, double, bool);
    double GetEffectiveAreaForMuon(double eta);
    double GetEffectiveAreaForElectron(double eta);

// ----------member data ---------------------------
    const bool run_on_mc_;
    const bool run_on_aod_;
    const bool egm_corrected_;
    const bool need_trigger_results_;
    const bool need_trigger_objects_;
    const bool need_muons_;
    const bool need_electrons_;
    const bool need_dileptons_;
    const bool need_photons_;
    const bool need_jets;
    const bool need_met_;
    const bool need_genparticles_;
    const bool need_pdf_weights_;
    const bool need_scale_variations_;

    edm::EDGetTokenT<edm::TriggerResults> trigger_results_token_;
    edm::EDGetTokenT<trigger::TriggerEvent> trigger_event_token_;
    edm::EDGetTokenT<std::vector<pat::TriggerObjectStandAlone>> trigger_objects_token_;

    edm::EDGetTokenT<reco::BeamSpot> beamspot_token_;
    edm::EDGetTokenT<reco::VertexCollection> vertices_token_;
    edm::EDGetTokenT<std::vector<PileupSummaryInfo>> pileup_token_;

    edm::EDGetTokenT<std::vector<pat::PackedCandidate>> pfcandidates_token_;  

    edm::EDGetTokenT<std::vector<pat::Muon>> muons_token_;  

    edm::EDGetTokenT<edm::View<pat::Electron>> electrons_token_;
    // edm::EDGetTokenT<edm::View<pat::Electron>> calibrated_electrons_token_;
    edm::EDGetTokenT<std::vector<reco::Conversion>> conversions_token_;

    edm::EDGetTokenT<edm::View<pat::Photon>> photons_token_;
    // edm::EDGetTokenT<edm::View<pat::Photon>> calibrated_photons_token_;

    edm::EDGetTokenT<double> rho_token_;
    edm::EDGetTokenT<double> rho_for_miniiso_token_;

    std::string pho_cutbased_loose_id_name_;
    std::string pho_cutbased_medium_id_name_;
    std::string pho_cutbased_tight_id_name_;
    std::string pho_cutbased_loose_id_results_name_;
    std::string pho_cutbased_medium_id_results_name_;
    std::string pho_cutbased_tight_id_results_name_;

    std::string pho_mva_wp90_id_name_;
    std::string pho_mva_wp80_id_name_;

    std::string pho_mva_value_name_;
    std::string pho_mva_category_name_;

    std::string full5x5sigmaietaietamap_name_;

    std::string pho_chiso_name_;
    std::string pho_nhiso_name_;
    std::string pho_phiso_name_;

    edm::FileInPath ea_file_path_;
    edm::FileInPath ea_for_ch_file_;
    edm::FileInPath ea_for_nh_file_;
    edm::FileInPath ea_for_ph_file_;

    edm::EDGetTokenT<std::vector<pat::Jet>> jets_token_;

    edm::EDGetTokenT<std::vector<pat::MET>> met_token_;
    
    edm::EDGetTokenT<std::vector<reco::GenParticle>> genparticles_token_;
    edm::EDGetTokenT<GenEventInfoProduct> generator_token_;
    edm::EDGetTokenT<LHEEventProduct> lhe_token_;

    std::string el_cutbased_veto_id_name_;
    std::string el_cutbased_loose_id_name_;
    std::string el_cutbased_medium_id_name_;
    std::string el_cutbased_tight_id_name_;
    std::string el_cutbased_heep_id_name_;
    std::string el_mva_wp90_id_name_;
    std::string el_mva_wp80_id_name_;

    std::string el_mva_value_name_;
    std::string el_mva_category_name_;

    ESHandle<MagneticField> B;
    edm::ESHandle<TransientTrackBuilder> theTTBuilder;    
    edm::Handle<reco::BeamSpot> beamSpotHandle;
    reco::BeamSpot beamSpot;
    edm::Handle<std::vector<reco::Vertex>> pvHandle;
    reco::Vertex vtx;

    std::map<std::string,TTree*> tree_;
    EventBuffer event_;   

    edm::EDGetTokenT<edm::TriggerResults> filters_token_;
    std::vector<std::string> trigger_list_;

    // GAIN
    edm::EDGetTokenT<EcalRecHitCollection> ecalCalibHitEBToken_;
};

#endif

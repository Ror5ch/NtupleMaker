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

#include "Physics/NtupleMaker/interface/NtupleMaker.h"

NtupleMaker::NtupleMaker(const edm::ParameterSet& iConfig):
    run_on_mc_                     {iConfig.getUntrackedParameter<bool>("run_on_mc")},    
    run_on_aod_                    {iConfig.getUntrackedParameter<bool>("run_on_aod")},    
    egm_corrected_                 {iConfig.getUntrackedParameter<bool>("egm_corrected")},    
    need_trigger_results_          {iConfig.getUntrackedParameter<bool>("need_trigger_results")},    
    need_trigger_objects_          {iConfig.getUntrackedParameter<bool>("need_trigger_objects")},    
    need_muons_                    {iConfig.getUntrackedParameter<bool>("need_muons")},    
    need_electrons_                {iConfig.getUntrackedParameter<bool>("need_electrons")},    
    need_dileptons_                {iConfig.getUntrackedParameter<bool>("need_dileptons")},    
    need_photons_                  {iConfig.getUntrackedParameter<bool>("need_photons")},    
    need_jets                      {iConfig.getUntrackedParameter<bool>("need_jets")},    
    need_met_                      {iConfig.getUntrackedParameter<bool>("need_met")},    
    need_genparticles_             {iConfig.getUntrackedParameter<bool>("need_genparticles")},
    need_pdf_weights_              {iConfig.getUntrackedParameter<bool>("need_pdf_weights")},
    need_scale_variations_         {iConfig.getUntrackedParameter<bool>("need_scale_variations")},
    trigger_results_token_         {consumes<edm::TriggerResults>                       (iConfig.getParameter<edm::InputTag>("TriggerResults"))},
    trigger_event_token_           {consumes<trigger::TriggerEvent>                     (iConfig.getParameter<edm::InputTag>("TriggerEvent"))},
    trigger_objects_token_         {consumes<std::vector<pat::TriggerObjectStandAlone>> (iConfig.getParameter<edm::InputTag>("TriggerObjects"))},
    beamspot_token_                {consumes<reco::BeamSpot>                            (iConfig.getParameter<edm::InputTag>("BeamSpot"))},
    vertices_token_                {consumes<std::vector<reco::Vertex>>                 (iConfig.getParameter<edm::InputTag>("Vertex"))},
    pileup_token_                  {consumes<std::vector<PileupSummaryInfo>>            (iConfig.getParameter<edm::InputTag>("PU"))},
    pfcandidates_token_            {consumes<std::vector<pat::PackedCandidate>>         (iConfig.getParameter<edm::InputTag>("PFCandidates"))},
    muons_token_                   {consumes<std::vector<pat::Muon>>                    (iConfig.getParameter<edm::InputTag>("Muons"))},
    electrons_token_               {consumes<edm::View<pat::Electron>>                  (iConfig.getParameter<edm::InputTag>("Electrons"))},
    conversions_token_             {consumes<std::vector<reco::Conversion>>             (iConfig.getParameter<edm::InputTag>("Conversions"))},
    photons_token_                 {consumes<edm::View<pat::Photon>>                    (iConfig.getParameter<edm::InputTag>("Photons"))},
    rho_token_                     {consumes<double>                                    (iConfig.getParameter<edm::InputTag>("rho"))},
    rho_for_miniiso_token_         {consumes<double>                                    (iConfig.getParameter<edm::InputTag>("miniRho"))},
    pho_cutbased_loose_id_name_    {iConfig.getUntrackedParameter<std::string>("phoLooseIdName")},
    pho_cutbased_medium_id_name_   {iConfig.getUntrackedParameter<std::string>("phoMediumIdName")},
    pho_cutbased_tight_id_name_    {iConfig.getUntrackedParameter<std::string>("phoTightIdName")},
    pho_mva_wp90_id_name_          {iConfig.getUntrackedParameter<std::string>("phoMvaWp90IdName")},
    pho_mva_wp80_id_name_          {iConfig.getUntrackedParameter<std::string>("phoMvaWp80IdName")},
    pho_mva_value_name_            {iConfig.getUntrackedParameter<std::string>("phoMvaValuesName")},
    pho_mva_category_name_         {iConfig.getUntrackedParameter<std::string>("phoMvaCategoriesName")},
    full5x5sigmaietaietamap_name_  {iConfig.getUntrackedParameter<std::string>("full5x5SigmaIEtaIEtaName")},
    pho_chiso_name_                {iConfig.getUntrackedParameter<std::string>("phoChargedIsolationName")},
    pho_nhiso_name_                {iConfig.getUntrackedParameter<std::string>("phoNeutralHadronIsolationName")},
    pho_phiso_name_                {iConfig.getUntrackedParameter<std::string>("phoPhotonIsolationName")},
    ea_file_path_                  {iConfig.getUntrackedParameter<edm::FileInPath>( "effAreaFile" )},
    ea_for_ch_file_                {iConfig.getUntrackedParameter<edm::FileInPath>( "effAreaChHadFile" )},
    ea_for_nh_file_                {iConfig.getUntrackedParameter<edm::FileInPath>( "effAreaNeuHadFile" )},
    ea_for_ph_file_                {iConfig.getUntrackedParameter<edm::FileInPath>( "effAreaPhoFile" )},
    jets_token_                    {consumes<std::vector<pat::Jet>>                     (iConfig.getParameter<edm::InputTag>("Jets"))},
    met_token_                     {consumes<std::vector<pat::MET>>                     (iConfig.getParameter<edm::InputTag>("MET"))},
    genparticles_token_            {consumes<std::vector<reco::GenParticle>>            (iConfig.getParameter<edm::InputTag>("GenParticles"))},
    generator_token_               {consumes<GenEventInfoProduct>                       (iConfig.getParameter<edm::InputTag>("Generator"))},
    el_cutbased_veto_id_name_      {iConfig.getUntrackedParameter<std::string>("eleVetoIdName")},
    el_cutbased_loose_id_name_     {iConfig.getUntrackedParameter<std::string>("eleLooseIdName")},
    el_cutbased_medium_id_name_    {iConfig.getUntrackedParameter<std::string>("eleMediumIdName")},
    el_cutbased_tight_id_name_     {iConfig.getUntrackedParameter<std::string>("eleTightIdName")},
    el_cutbased_heep_id_name_      {iConfig.getUntrackedParameter<std::string>("eleHeepIdName")},
    el_mva_wp90_id_name_           {iConfig.getUntrackedParameter<std::string>("eleMvaWp90IdName")},
    el_mva_wp80_id_name_           {iConfig.getUntrackedParameter<std::string>("eleMvaWp80IdName")},
    el_mva_value_name_             {iConfig.getUntrackedParameter<std::string>("eleMvaValuesName")},
    el_mva_category_name_          {iConfig.getUntrackedParameter<std::string>("eleMvaCategoriesName")},
    filters_token_                 {consumes<edm::TriggerResults>                       (iConfig.getParameter<edm::InputTag>("Filters"))},
    trigger_list_                  {iConfig.getUntrackedParameter<std::vector<std::string>>("trigger_list")},
    ecalCalibHitEBToken_           {consumes<EcalRecHitCollection>                      (iConfig.getParameter<edm::InputTag>("reducedEBRecHits"))}
    {}

void NtupleMaker::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) 
{
    event_.Initialize();

    iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder",theTTBuilder);
    iSetup.get<IdealMagneticFieldRecord>().get(B);

    iEvent.getByToken(beamspot_token_, beamSpotHandle);
    beamSpot = (*beamSpotHandle);

    iEvent.getByToken(vertices_token_, pvHandle);
    vtx = pvHandle->front();

    event_.run          = iEvent.id().run();
    event_.event        = iEvent.id().event();
    event_.ls           = iEvent.id().luminosityBlock();
    event_.num_vertices = pvHandle->size();

	FillWithFilters(iEvent);
    if (need_trigger_results_) FillWithTriggerResults(iEvent);
    if (need_muons_) FillWithMuons(iEvent);
    if (need_electrons_) FillWithElectrons(iEvent);
    if (need_photons_) FillWithPhotons(iEvent);
    if (need_jets) FillWithJets(iEvent);

    if (run_on_mc_) 
    {
        FillWithPileup(iEvent);
        if (need_genparticles_) FillWithGenparticles(iEvent);
    }

    tree_["physics"]->Fill();
}

NtupleMaker::~NtupleMaker() 
{
    
}

void NtupleMaker::beginJob() 
{
    edm::Service<TFileService> fs;
    tree_["physics"] = fs->make<TTree>("physics", "physics");
    event_.SetBranchWrite(tree_["physics"]);
}

void NtupleMaker::endJob() 
{

}

void NtupleMaker::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
   // The following says we do not know what parameters are allowed so do no validation
   // Please change this to state exactly what you do use, even if it is no parameters
   edm::ParameterSetDescription desc;
   desc.setUnknown();
   descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(NtupleMaker);

import FWCore.ParameterSet.Config as cms

tree = cms.EDAnalyzer("NtupleMaker",
    ## Flags
    run_on_mc             = cms.untracked.bool(False),
    run_on_aod            = cms.untracked.bool(False),
    egm_corrected         = cms.untracked.bool(False),
    need_trigger_results  = cms.untracked.bool(True),
    need_trigger_objects  = cms.untracked.bool(False),
    need_muons            = cms.untracked.bool(True),
    need_electrons        = cms.untracked.bool(True),
    need_dileptons        = cms.untracked.bool(False),
    need_photons          = cms.untracked.bool(True),
    need_jets             = cms.untracked.bool(False),
    need_met              = cms.untracked.bool(False),
    need_genparticles     = cms.untracked.bool(False),
    need_pdf_weights      = cms.untracked.bool(False),
    need_scale_variations = cms.untracked.bool(False),

    ## Trigger & event tags
    Filters        = cms.InputTag("TriggerResults","","RECO"),
    TriggerResults = cms.InputTag("TriggerResults","","HLT"),
    TriggerEvent   = cms.InputTag("hltTriggerSummaryAOD","","HLT"),
    TriggerObjects = cms.InputTag("selectedPatTrigger"),
    Vertex         = cms.InputTag("offlineSlimmedPrimaryVertices"),
    PU             = cms.InputTag("slimmedAddPileupInfo"),
    BeamSpot       = cms.InputTag("offlineBeamSpot"),
    PFCandidates   = cms.InputTag("packedPFCandidates"),
    trigger_list   = cms.untracked.vstring(
        "HLT_Mu50_v", "HLT_TkMu50_v", "HLT_IsoMu24_v", "HLT_IsoTkMu24_v", 
        "HLT_DoublePhoton60_v", "HLT_Photon165_HE10_v", "HLT_Photon175_v",
        "HLT_Ele27_WPTight_Gsf_v", "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v", "HLT_DoubleEle33_CaloIdL_MW_v"
    ),

    ## Muon tags
    Muons     = cms.InputTag("slimmedMuons"),

    ## Electron tags
    Electrons           = cms.InputTag("slimmedElectrons"),
    CalibratedElectrons = cms.InputTag("calibratedPatElectrons"),
    Conversions         = cms.InputTag("reducedEgamma:reducedConversions"),

    ## Photon tags
    Photons           = cms.InputTag("slimmedPhotons"),
    CalibratedPhotons = cms.InputTag("calibratedPatPhotons"),
    rho               = cms.InputTag("fixedGridRhoFastjetAll"),
    miniRho           = cms.InputTag("fixedGridRhoFastjetCentralNeutral"),

    ## JetMET tags
    Jets = cms.InputTag("slimmedJets"),
    MET  = cms.InputTag("slimmedMETs"),

    ## GEN tags
    GenParticles = cms.InputTag("prunedGenParticles"),
    Generator    = cms.InputTag("generator"),

    ## EGM ID
    eleVetoIdBoolMap          = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-veto"),
    eleLooseIdBoolMap         = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-loose"),
    eleMediumIdBoolMap        = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-medium"),
    eleTightIdBoolMap         = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-Summer16-80X-V1-tight"),
    eleHeepIdBoolMap          = cms.InputTag("egmGsfElectronIDs:heepElectronID-HEEPV70"),
    eleMvaWp90IdBoolMap       = cms.InputTag("egmGsfElectronIDs:mvaEleID-Spring16-GeneralPurpose-V1-wp90"),
    eleMvaWp80IdBoolMap       = cms.InputTag("egmGsfElectronIDs:mvaEleID-Spring16-GeneralPurpose-V1-wp80"),
    eleMvaValuesMap           = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Values"),
    eleMvaCategoriesMap       = cms.InputTag("electronMVAValueMapProducer:ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Categories"),
    phoLooseIdBoolMap         = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring16-V2p2-loose"),
    phoMediumIdBoolMap        = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring16-V2p2-medium"),
    phoTightIdBoolMap         = cms.InputTag("egmPhotonIDs:cutBasedPhotonID-Spring16-V2p2-tight"),
    phoMvaWp90IdBoolMap       = cms.InputTag("egmPhotonIDs:mvaPhoID-Spring16-nonTrig-V1-wp90"),
    phoMvaWp80IdBoolMap       = cms.InputTag("egmPhotonIDs:mvaPhoID-Spring16-nonTrig-V1-wp80"),
    phoMvaValuesMap           = cms.InputTag("photonMVAValueMapProducer:PhotonMVAEstimatorRun2Spring16NonTrigV1Values"),
    phoMvaCategoriesMap       = cms.InputTag("photonMVAValueMapProducer:PhotonMVAEstimatorRun2Spring16NonTrigV1Categories"),
    full5x5SigmaIEtaIEtaMap   = cms.InputTag("photonIDValueMapProducer:phoFull5x5SigmaIEtaIEta"),
    phoChargedIsolation       = cms.InputTag("photonIDValueMapProducer:phoChargedIsolation"),
    phoNeutralHadronIsolation = cms.InputTag("photonIDValueMapProducer:phoNeutralHadronIsolation"),
    phoPhotonIsolation        = cms.InputTag("photonIDValueMapProducer:phoPhotonIsolation"),

    ## EA
    effAreaFile       = cms.untracked.FileInPath("RecoEgamma/ElectronIdentification/data/Summer16/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_80X.txt"),
    effAreaChHadFile  = cms.untracked.FileInPath("RecoEgamma/PhotonIdentification/data/Spring16/effAreaPhotons_cone03_pfChargedHadrons_90percentBased.txt"),
    effAreaNeuHadFile = cms.untracked.FileInPath("RecoEgamma/PhotonIdentification/data/Spring16/effAreaPhotons_cone03_pfNeutralHadrons_90percentBased.txt"),
    effAreaPhoFile    = cms.untracked.FileInPath("RecoEgamma/PhotonIdentification/data/Spring16/effAreaPhotons_cone03_pfPhotons_90percentBased.txt")
)

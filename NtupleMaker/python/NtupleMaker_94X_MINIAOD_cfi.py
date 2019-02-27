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
        "HLT_Ele27_WPTight_Gsf_v", "HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v", "HLT_DoubleEle33_CaloIdL_MW_v", "HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v"
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

    ## EBRecHits (for systematics related to the gain switch issue in 2016)
    reducedEBRecHits = cms.InputTag("reducedEgamma", "reducedEBRecHits", "PAT"),

    ## JetMET tags
    Jets = cms.InputTag("slimmedJets"),
    MET  = cms.InputTag("slimmedMETs"),

    ## GEN tags
    GenParticles = cms.InputTag("prunedGenParticles"),
    Generator    = cms.InputTag("generator"),

    ## EGM ID
    eleVetoIdName                 = cms.untracked.string("cutBasedElectronID-Summer16-80X-V1-veto"),
    eleLooseIdName                = cms.untracked.string("cutBasedElectronID-Summer16-80X-V1-loose"),
    eleMediumIdName               = cms.untracked.string("cutBasedElectronID-Summer16-80X-V1-medium"),
    eleTightIdName                = cms.untracked.string("cutBasedElectronID-Summer16-80X-V1-tight"),
    eleHeepIdName                 = cms.untracked.string("heepElectronID-HEEPV70"),
    eleMvaWp90IdName              = cms.untracked.string("mvaEleID-Spring16-GeneralPurpose-V1-wp90"),
    eleMvaWp80IdName              = cms.untracked.string("mvaEleID-Spring16-GeneralPurpose-V1-wp80"),
    eleMvaValuesName              = cms.untracked.string("ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Values"),
    eleMvaCategoriesName          = cms.untracked.string("ElectronMVAEstimatorRun2Spring16GeneralPurposeV1Categories"),
    phoLooseIdName                = cms.untracked.string("cutBasedPhotonID-Spring16-V2p2-loose"),
    phoMediumIdName               = cms.untracked.string("cutBasedPhotonID-Spring16-V2p2-medium"),
    phoTightIdName                = cms.untracked.string("cutBasedPhotonID-Spring16-V2p2-tight"),
    phoMvaWp90IdName              = cms.untracked.string("mvaPhoID-Spring16-nonTrig-V1-wp90"),
    phoMvaWp80IdName              = cms.untracked.string("mvaPhoID-Spring16-nonTrig-V1-wp80"),
    phoMvaValuesName              = cms.untracked.string("PhotonMVAEstimatorRun2Spring16NonTrigV1Values"),
    phoMvaCategoriesName          = cms.untracked.string("PhotonMVAEstimatorRun2Spring16NonTrigV1Categories"),
    full5x5SigmaIEtaIEtaName      = cms.untracked.string("phoFull5x5SigmaIEtaIEta"),
    phoChargedIsolationName       = cms.untracked.string("phoChargedIsolation"),
    phoNeutralHadronIsolationName = cms.untracked.string("phoNeutralHadronIsolation"),
    phoPhotonIsolationName        = cms.untracked.string("phoPhotonIsolation"),

    ## EA
    effAreaFile       = cms.untracked.FileInPath("RecoEgamma/ElectronIdentification/data/Summer16/effAreaElectrons_cone03_pfNeuHadronsAndPhotons_80X.txt"),
    effAreaChHadFile  = cms.untracked.FileInPath("RecoEgamma/PhotonIdentification/data/Spring16/effAreaPhotons_cone03_pfChargedHadrons_90percentBased.txt"),
    effAreaNeuHadFile = cms.untracked.FileInPath("RecoEgamma/PhotonIdentification/data/Spring16/effAreaPhotons_cone03_pfNeutralHadrons_90percentBased.txt"),
    effAreaPhoFile    = cms.untracked.FileInPath("RecoEgamma/PhotonIdentification/data/Spring16/effAreaPhotons_cone03_pfPhotons_90percentBased.txt")
)

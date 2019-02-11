import FWCore.ParameterSet.Config as cms
process = cms.Process("NtupleProduction")

isMC = False

## MessageLogger
process.load("FWCore.MessageLogger.MessageLogger_cfi")

## Options and Output Report
process.options = cms.untracked.PSet( 
    wantSummary = cms.untracked.bool(True) 
)
process.MessageLogger.cerr.FwkReport.reportEvery = 100

## Source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('')
    # fileNames = cms.untracked.vstring('/store/data/Run2016B/SingleMuon/MINIAOD/03Feb2017_ver2-v2/80000/FE103CFE-6EEB-E611-91D4-0025904C51D8.root')
)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

## Geometry and Detector Conditions (needed for a few patTuple production steps)
process.load("Configuration.Geometry.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.GlobalTag.globaltag = cms.string('80X_dataRun2_2016SeptRepro_v7')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('ntuple.root')
)

## EGM 80X regression
from EgammaAnalysis.ElectronTools.regressionWeights_cfi import regressionWeights
process = regressionWeights(process)

## Manual load
import FWCore.ParameterSet.Config as cms

from PhysicsTools.PatAlgos.slimming.modifiedElectrons_cfi import modifiedElectrons
from PhysicsTools.PatAlgos.slimming.modifiedPhotons_cfi import modifiedPhotons
from EgammaAnalysis.ElectronTools.regressionModifier_cfi import regressionModifier

regressionModifier.ecalrechitsEB = cms.InputTag("reducedEgamma:reducedEBRecHits")
regressionModifier.ecalrechitsEE = cms.InputTag("reducedEgamma:reducedEERecHits")
regressionModifier.useLocalFile  = cms.bool(False)

egamma_modifications = cms.VPSet( )
egamma_modifications.append( regressionModifier )

modifiedElectrons.modifierConfig.modifications = egamma_modifications
modifiedPhotons.modifierConfig.modifications   = egamma_modifications

process.modifiedElectrons = modifiedElectrons
process.modifiedPhotons = modifiedPhotons
process.regressionApplication = cms.Sequence( process.modifiedElectrons * process.modifiedPhotons )

## EGM scale and smearing correciton
process.load('Configuration.StandardSequences.Services_cff')
process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
    calibratedPatElectrons  = cms.PSet( 
        initialSeed = cms.untracked.uint32(12345),
        engineName = cms.untracked.string('TRandom3'),
   ),
    calibratedPatPhotons  = cms.PSet( 
        initialSeed = cms.untracked.uint32(12345),
        engineName = cms.untracked.string('TRandom3'),
   )
)

process.load('EgammaAnalysis.ElectronTools.calibratedPatElectronsRun2_cfi')
process.load('EgammaAnalysis.ElectronTools.calibratedPatPhotonsRun2_cfi')

process.calibratedPatElectrons.electrons = cms.InputTag("modifiedElectrons")
process.calibratedPatPhotons.photons = cms.InputTag("modifiedPhotons")

process.calibratedPatElectrons.isMC = isMC
process.calibratedPatPhotons.isMC = isMC

from PhysicsTools.SelectorUtils.tools.vid_id_tools import *

useAOD = False

if useAOD == True :
    dataFormat = DataFormat.AOD
else :
    dataFormat = DataFormat.MiniAOD

switchOnVIDPhotonIdProducer(process, dataFormat)
switchOnVIDElectronIdProducer(process, dataFormat)

my_phoId_modules = [
    'RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Spring16_V2p2_cff',
    'RecoEgamma.PhotonIdentification.Identification.mvaPhotonID_Spring16_nonTrig_V1_cff'
]
my_eleId_modules = [
    'RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_Summer16_80X_V1_cff',
    'RecoEgamma.ElectronIdentification.Identification.mvaElectronID_Spring16_GeneralPurpose_V1_cff',
    'RecoEgamma.ElectronIdentification.Identification.heepElectronID_HEEPV70_cff'
]

process.load("RecoEgamma.ElectronIdentification.ElectronIDValueMapProducer_cfi")
process.electronIDValueMapProducer.srcMiniAOD = cms.InputTag('slimmedElectrons')
process.electronMVAValueMapProducer.srcMiniAOD = cms.InputTag('slimmedElectrons')
process.photonIDValueMapProducer.srcMiniAOD = cms.InputTag('slimmedPhotons')
process.photonMVAValueMapProducer.srcMiniAOD = cms.InputTag('slimmedPhotons')

for idmod in my_phoId_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDPhotonSelection)
for idmod in my_eleId_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)

process.load("Physics.NtupleMaker.NtupleMaker_80X_MINIAOD_cfi")
process.tree.egm_corrected = cms.untracked.bool(True)
process.tree.run_on_mc = isMC

process.p = cms.Path(
    process.regressionApplication*
    process.calibratedPatElectrons*
    process.calibratedPatPhotons*
    process.egmPhotonIDSequence*
    process.egmGsfElectronIDSequence*
    process.tree
)

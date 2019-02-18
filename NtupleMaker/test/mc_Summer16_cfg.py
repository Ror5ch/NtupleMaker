import FWCore.ParameterSet.Config as cms
process = cms.Process("NtupleProduction")

isMC = True

## MessageLogger
process.load("FWCore.MessageLogger.MessageLogger_cfi")

## Options and Output Report
process.options = cms.untracked.PSet( 
    wantSummary = cms.untracked.bool(True) 
)
process.MessageLogger.cerr.FwkReport.reportEvery = 100

## Source
process.source = cms.Source("PoolSource",
    # fileNames = cms.untracked.vstring('')
    fileNames = cms.untracked.vstring('file:F62535BD-1CBD-E811-9F9F-0CC47AF9B302.root')
    # fileNames = cms.untracked.vstring('/store/mc/RunIISummer16MiniAODv3/ZGTo2LG_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PUMoriond17_94X_mcRun2_asymptotic_v3_ext1-v1/110000/30395BDD-6BBC-E811-A14D-0025904C6508.root')
)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))

## Geometry and Detector Conditions (needed for a few patTuple production steps)
process.load("Configuration.Geometry.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.GlobalTag.globaltag = cms.string('94X_mcRun2_asymptotic_v3')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('ntuple.root')
)

process.load("Physics.NtupleMaker.NtupleMaker_94X_MINIAOD_cfi")
process.tree.egm_corrected = cms.untracked.bool(True)
process.tree.run_on_mc = isMC
process.tree.need_genparticles = isMC

process.p = cms.Path(
    process.tree
)

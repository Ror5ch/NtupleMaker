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
    # fileNames = cms.untracked.vstring('')
    fileNames = cms.untracked.vstring('/store/data/Run2016B/SinglePhoton/MINIAOD/17Jul2018_ver2-v1/50000/E87394E4-DC8B-E811-B452-0242AC1C0502.root')
)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(-1))

## Geometry and Detector Conditions (needed for a few patTuple production steps)
process.load("Configuration.Geometry.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.GlobalTag.globaltag = cms.string('94X_dataRun2_v10')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('ntuple.root')
)

process.load("Physics.NtupleMaker.NtupleMaker_94X_MINIAOD_cfi")
process.tree.egm_corrected = cms.untracked.bool(True)
process.tree.run_on_mc = isMC
process.tree.reducedEBRecHits = cms.InputTag("reducedEgamma", "reducedEBRecHits", "DQM")

process.p = cms.Path(
    process.tree
)

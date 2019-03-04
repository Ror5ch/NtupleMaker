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
    fileNames = cms.untracked.vstring('/store/data/Run2016G/DoubleEG/MINIAOD/17Jul2018-v1/90000/E646696D-9F95-E811-AC0F-002590FD0F36.root'),
    lumisToProcess = cms.untracked.VLuminosityBlockRange("279766:1-279766:999999")
)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))

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

# proton reconstruction
process.load("RecoCTPPS.ProtonReconstruction.year_2016.ctppsProtonReconstruction_cfi")

process.p = cms.Path(
    process.ctppsProtonReconstruction *
    process.tree
)

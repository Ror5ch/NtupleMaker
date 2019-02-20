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
    fileNames = cms.untracked.vstring('/store/data/Run2017B/SinglePhoton/MINIAOD/31Mar2018-v1/90000/3AF2EAE7-BB37-E811-A5AA-0CC47A4C8EB6.root')
)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))

## Geometry and Detector Conditions (needed for a few patTuple production steps)
process.load("Configuration.Geometry.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.GlobalTag.globaltag = cms.string('94X_dataRun2_ReReco_EOY17_v6')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('ntuple.root')
)

process.load("Physics.NtupleMaker.NtupleMaker_94X_MINIAOD_cfi")
process.tree.egm_corrected = cms.untracked.bool(True)
process.tree.run_on_mc = isMC

# Fix on a bug in the ECAL-Tracker momentum combination
from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
setupEgammaPostRecoSeq(process, runVID=True, era='2017-Nov17ReReco')

process.p = cms.Path(
    process.egammaPostRecoSeq *
    process.tree
)

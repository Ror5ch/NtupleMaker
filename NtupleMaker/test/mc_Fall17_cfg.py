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
    fileNames = cms.untracked.vstring('/store/mc/RunIIFall17MiniAODv2/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/MINIAODSIM/PU2017_12Apr2018_new_pmx_94X_mc2017_realistic_v14_ext1-v1/270000/F063F369-B0EA-E811-BC7B-00010100097B.root')
)

process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))

## Geometry and Detector Conditions (needed for a few patTuple production steps)
process.load("Configuration.Geometry.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
process.GlobalTag.globaltag = cms.string('94X_mc2017_realistic_v14')
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")

process.TFileService = cms.Service("TFileService",
    fileName = cms.string('ntuple.root')
)

process.load("Physics.NtupleMaker.NtupleMaker_94X_MINIAOD_cfi")
process.tree.egm_corrected = cms.untracked.bool(True)
process.tree.run_on_mc = isMC
process.tree.need_genparticles = isMC

# Fix on a bug in the ECAL-Tracker momentum combination
from RecoEgamma.EgammaTools.EgammaPostRecoTools import setupEgammaPostRecoSeq
setupEgammaPostRecoSeq(process, runVID=True, era='2017-Nov17ReReco')

process.p = cms.Path(
    process.egammaPostRecoSeq *
    process.tree
)

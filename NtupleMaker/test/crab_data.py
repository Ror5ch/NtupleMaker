from CRABClient.UserUtilities import config
config = config()

config.JobType.pluginName = 'Analysis'
config.JobType.maxJobRuntimeMin = 240

config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 20
config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions16/13TeV/ReReco/Final/Cert_271036-284044_13TeV_23Sep2016ReReco_Collisions16_JSON.txt'
config.Data.outLFNDirBase = '/store/user/knam'

config.Site.storageSite = 'T2_KR_KNU'

if __name__ == '__main__':
    
    from CRABAPI.RawCommand import crabCommand
    
    for pd in ["SingleMuon", "DoubleEG"]:
        config.General.workArea = '%s' % pd
        config.JobType.psetName = 'data_Run2016BCDEF_cfg.py'

        config.General.requestName = 'Run2016B_v1'
        config.Data.inputDataset = '/%s/Run2016B-03Feb2017_ver2-v2/MINIAOD' % pd
        crabCommand('submit', config = config)
        
        config.General.requestName = 'Run2016C_v1'
        config.Data.inputDataset = '/%s/Run2016C-03Feb2017-v1/MINIAOD' % pd
        crabCommand('submit', config = config)
        
        config.General.requestName = 'Run2016D_v1'
        config.Data.inputDataset = '/%s/Run2016D-03Feb2017-v1/MINIAOD' % pd
        crabCommand('submit', config = config)
        
        config.General.requestName = 'Run2016E_v1'
        config.Data.inputDataset = '/%s/Run2016E-03Feb2017-v1/MINIAOD' % pd
        crabCommand('submit', config = config)
        
        config.General.requestName = 'Run2016F_v1'
        config.Data.inputDataset = '/%s/Run2016F-03Feb2017-v1/MINIAOD' % pd
        crabCommand('submit', config = config)
        
        config.JobType.psetName = 'data_Run2016G_cfg.py'

        config.General.requestName = 'Run2016G_v1'
        config.Data.inputDataset = '/%s/Run2016G-03Feb2017-v1/MINIAOD' % pd
        crabCommand('submit', config = config)
        
        config.JobType.psetName = 'data_Run2016H_cfg.py'

        config.General.requestName = 'Run2016Hv2_v1'
        config.Data.inputDataset = '/%s/Run2016H-03Feb2017_ver2-v1/MINIAOD' % pd
        crabCommand('submit', config = config)
        
        config.General.requestName = 'Run2016Hv3_v1'
        config.Data.inputDataset = '/%s/Run2016H-03Feb2017_ver3-v1/MINIAOD' % pd
        crabCommand('submit', config = config)

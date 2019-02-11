from CRABClient.UserUtilities import config
config = config()

config.General.workArea = 'GluGluSpin0ToZG_ZToLL'

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'mc_Summer16_cfg.py'
config.JobType.maxJobRuntimeMin = 120

config.Data.inputDBS = 'global'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.outLFNDirBase = '/store/user/knam'

config.Site.storageSite = 'T2_KR_KNU'

if __name__ == '__main__':

    from CRABAPI.RawCommand import crabCommand

    for width in ["0p014", "5p6"]:
        masses = [300, 400, 500, 750, 1000, 1500, 2000, 3000];
        if width == "0p014":
            masses += [1250, 1750, 2500]
        for mass in masses:
            config.General.requestName = 'w%s_M%i_v1' % (width, mass)
            config.Data.inputDataset = '/GluGluSpin0ToZG_ZToLL_W-%s_M-%i_TuneCUEP8M1_13TeV-pythia8/RunIISummer16MiniAODv2-PUMoriond17_80X_mcRun2_asymptotic_2016_TrancheIV_v6-v1/MINIAODSIM' % (width, mass)
            crabCommand('submit', config = config)
    
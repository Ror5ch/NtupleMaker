# How to setup
cmsrel CMSSW_8_0_26_patch1
cd CMSSW_8_0_26_patch1/src
cmsenv 
git cms-init
git cms-merge-topic Sam-Harper:HEEPV70VID_8010_ReducedCheckout
git cms-merge-topic ikrav:egm_id_80X_v3 
git cms-merge-topic ikrav:egm_id_80X_v3_photons
git cms-merge-topic cms-egamma:EGM_gain_v1
cd EgammaAnalysis/ElectronTools/data
git clone https://github.com/ECALELFS/ScalesSmearings.git
cd $CMSSW_BASE/src
git clone git@github.com:Ror5ch/NtupleMaker.git .
scram b -j 4

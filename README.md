# How to setup
cmsrel CMSSW_9_4_10\
cd CMSSW_9_4_10/src\
cmsenv\
--- Only for 2017 data & mc ---\
git cms-init\
git cms-merge-topic cms-egamma:EgammaID_949\
git cms-merge-topic cms-egamma:EgammaPostRecoTools_940\
-------------------------------\
cd Physics\
git clone https://github.com/Ror5ch/NtupleMaker.git .\
git checkout 94X\
cd ..\
scram b -j 4

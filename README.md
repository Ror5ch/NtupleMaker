# How to setup
cmsrel CMSSW_9_4_10\
cd CMSSW_9_4_10/src\
cmsenv\
cd Physics\
git clone https://github.com/Ror5ch/NtupleMaker.git .\
git checkout 94X\
cd ..\
scram b -j 4

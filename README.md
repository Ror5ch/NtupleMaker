# How to setup
cmsrel CMSSW_9_4_11\
cd CMSSW_9_4_11/src\
cmsenv\
git cms-init\
git remote add ctpps git@github.com:CTPPS/cmssw.git\
git fetch ctpps\
git checkout -b test ctpps/ctpps_initial_proton_reconstruction_CMSSW_10_2_0\
git cms-addpkg \\\
CondFormats/CTPPSOpticsObjects \\\
DataFormats/ProtonReco \\\
IOMC/EventVertexGenerators \\\
IOMC/ParticleGuns \\\
RecoCTPPS/ProtonReconstruction \\\
RecoCTPPS/TotemRPLocal \\\
SimCTPPS/OpticsParameterisation \\\
Validation/CTPPS \\\
CondFormats/RunInfo \\\ 
CondFormats/DataRecord
git clone https://github.com/Ror5ch/NtupleMaker.git Physics -b 94X_PPS\
scram b -j 4

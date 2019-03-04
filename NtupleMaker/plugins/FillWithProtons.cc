#include "Physics/NtupleMaker/interface/NtupleMaker.h"

void FillWithProtons(const edm::Event&)
{
    edm::Handle<std::vector<reco::ProtonTrack>> protons;
    event.getByToken(protons_token_, protons);

    event_.num_protons = protons->size();

    auto index = 0;
    for (const auto& proton : protons)
    {
        event_.proton_xi[index] = proton.xi();
        event_.proton_method[index] = proton.method;
        event_.proton_lhcSector[index] = proton.lhcSector;
        event_.proton_isValid[index] = proton.valid();

        ++index;
    }
}
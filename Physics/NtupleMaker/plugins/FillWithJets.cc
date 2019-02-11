#include "Physics/NtupleMaker/interface/NtupleMaker.h"

void NtupleMaker::FillWithJets(const edm::Event& iEvent) 
{
    edm::Handle<std::vector<pat::Jet>> jets;
    iEvent.getByToken(jets_token_, jets);

    event_.num_jets = jets->size();
    if (event_.num_jets == 0) return;

    int idx = 0;
    for (const auto& jet : *jets) 
    {
        event_.jet_pt[idx] = jet.pt();
        event_.jet_eta[idx] = jet.eta();
        event_.jet_phi[idx] = jet.phi();
        event_.jet_charge[idx] = jet.jetCharge();
        event_.jet_flavor[idx] = jet.partonFlavour();
        event_.jet_bTag[idx] = jet.bDiscriminator("pfCombinedInclusiveSecondaryVertexV2BJetTags");
        event_.jet_CHF[idx] = jet.chargedHadronEnergyFraction();
        event_.jet_NHF[idx] = jet.neutralHadronEnergyFraction();
        event_.jet_CEMF[idx] = jet.chargedEmEnergyFraction();
        event_.jet_NEMF[idx] = jet.neutralEmEnergyFraction();
        event_.jet_CHM[idx] = jet.chargedMultiplicity();
        event_.jet_NHM[idx] = jet.neutralMultiplicity();
        event_.jet_MUF[idx]  = jet.muonEnergyFraction();

        ++idx;
    }
}
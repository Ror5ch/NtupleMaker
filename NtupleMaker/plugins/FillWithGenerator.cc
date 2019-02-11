#include "Physics/NtupleMaker/interface/NtupleMaker.h"

void NtupleMaker::FillWithPileup(const edm::Event& iEvent)
{
    edm::Handle<std::vector<PileupSummaryInfo>> pileup_info;
    iEvent.getByToken(pileup_token_, pileup_info);
    std::vector<PileupSummaryInfo>::const_iterator PVI;

    int npv = -999;
    int npvin = -999;

    for (PVI = pileup_info->begin(); PVI != pileup_info->end(); ++PVI) 
    {
        if (PVI->getBunchCrossing() == 0) 
        {
            npvin = PVI->getPU_NumInteractions(); // in time only
            npv = PVI->getTrueNumInteractions(); // in and out of time
            continue;
        }
    }
    
    event_.num_pu = npv;
    event_.num_pu_in_time = npvin;
}
void NtupleMaker::FillWithGenparticles(const edm::Event& iEvent) 
{
    edm::Handle<std::vector<reco::GenParticle>> particles;
    iEvent.getByToken(genparticles_token_, particles);

    edm::Handle<GenEventInfoProduct> genInfo;
    iEvent.getByToken(generator_token_, genInfo);

    if (genInfo->weight() > 0) event_.weight = 1.0;
    else event_.weight = -1.0;

    if (particles->size() == 0) return;

    int index = 0;
    for (std::vector<reco::GenParticle>::const_iterator particle = particles->begin(); particle != particles->end(); ++particle)
    {
        // if (abs(particle->pdgId()) < 10 || abs(particle->pdgId()) == 11 || abs(particle->pdgId()) == 13 || abs(particle->pdgId()) == 15 || abs(particle->pdgId()) == 21 || abs(particle->pdgId()) == 22 || abs(particle->pdgId()) == 12 || abs(particle->pdgId()) == 14 || abs(particle->pdgId()) == 16)
        if (abs(particle->pdgId()) == 11 || abs(particle->pdgId()) == 13 || abs(particle->pdgId()) == 15 || abs(particle->pdgId()) == 22)
        {
            event_.gen_particle_pt[index] = particle->pt(); 
            event_.gen_particle_eta[index] = particle->eta();
            event_.gen_particle_phi[index] = particle->phi();
            event_.gen_particle_energy[index] = particle->energy();
            event_.gen_particle_mass[index] = particle->mass();
            event_.gen_particle_charge[index] = particle->charge();
            event_.gen_particle_id[index] = particle->pdgId(); 
            event_.gen_particle_status[index] = particle->status();
            event_.gen_particle_mother[index] = particle->mother(0)->pdgId();

            event_.gen_particle_isDirectHardProcessTauDecayProductFinalState[index] = particle->isDirectHardProcessTauDecayProductFinalState();
            event_.gen_particle_isDirectPromptTauDecayProductFinalState[index] = particle->isDirectPromptTauDecayProductFinalState();
            event_.gen_particle_isHardProcess[index] = particle->isHardProcess();
            event_.gen_particle_isLastCopy[index] = particle->isLastCopy();
            event_.gen_particle_isLastCopyBeforeFSR[index] = particle->isLastCopyBeforeFSR();
            event_.gen_particle_isPromptDecayed[index] = particle->isPromptDecayed();
            event_.gen_particle_isPromptFinalState[index] = particle->isPromptFinalState();
            event_.gen_particle_fromHardProcessFinalState[index] = particle->fromHardProcessFinalState();
            event_.gen_particle_fromHardProcessDecayed[index] = particle->fromHardProcessDecayed();
            event_.gen_particle_fromHardProcessBeforeFSR[index] = particle->fromHardProcessBeforeFSR();

            index++;
        }
    }
    event_.num_gen_particles = index;
}
#include "Physics/NtupleMaker/interface/NtupleMaker.h"

double NtupleMaker::GetMiniIsolation(
    const edm::Handle<pat::PackedCandidateCollection>& pfcands,
    const reco::Candidate* ptcl,  
    double r_iso_min, double r_iso_max, double kt_scale,
    double rho, bool use_effective_area) 
{

    if (ptcl->pt()<5.) return 99999.;

    double deadcone_nh{0.}; double deadcone_ch{0.};
    double deadcone_ph{0.}; double deadcone_pu{0.};
	double effective_area{1.};
    if (ptcl->isElectron())
    {
        if (fabs(ptcl->eta())>1.479) {deadcone_ch = 0.015; deadcone_pu = 0.015; deadcone_ph = 0.08;}
		effective_area = GetEffectiveAreaForElectron(ptcl->eta());
    } 
    else if (ptcl->isMuon()) 
    {
        deadcone_ch = 0.0001; deadcone_pu = 0.01; deadcone_ph = 0.01;deadcone_nh = 0.01;  
		effective_area = GetEffectiveAreaForMuon(ptcl->eta());
    } 

    double iso_nh{0.}; double iso_ch{0.}; 
    double iso_ph{0.}; double iso_pu{0.};
    double ptThresh{0.5};
    if (ptcl->isElectron()) ptThresh = 0;
    double r_iso = max(r_iso_min,min(r_iso_max, kt_scale/ptcl->pt()));

    for (const pat::PackedCandidate &pfc : *pfcands) 
    {
        if (abs(pfc.pdgId()) < 7) continue;

        double dr = deltaR(pfc, *ptcl);
        if (dr > r_iso) continue;

        //////////////////  NEUTRALS  /////////////////////////
        if (pfc.charge() == 0)
        {
            if (pfc.pt() > ptThresh)
            {
                /////////// PHOTONS ////////////
                if (abs(pfc.pdgId()) == 22)
                {
                    if (dr < deadcone_ph) continue;
                    iso_ph += pfc.pt();
                } 
                /////////// NEUTRAL HADRONS ////////////
                else if (abs(pfc.pdgId()) == 130) 
                {
                    if (dr < deadcone_nh) continue;
                    iso_nh += pfc.pt();
                }
            }
        } 
        //////////////////  CHARGED from PV  /////////////////////////
        else if (pfc.fromPV() > 1)
        {
            if (abs(pfc.pdgId()) == 211) 
            {
                if (dr < deadcone_ch) continue;
                iso_ch += pfc.pt();
            }
        } 
        //////////////////  CHARGED from PU  /////////////////////////
        else {
            if (pfc.pt() > ptThresh)
            {
                if (dr < deadcone_pu) continue;
                iso_pu += pfc.pt();
            }
        }
    } 

    double iso{iso_ph + iso_nh};
    iso -= (use_effective_area) ? effective_area*rho*r_iso*r_iso/(0.3*0.3) : 0.5*iso_pu;

    if (iso>0) iso += iso_ch;
    else iso = iso_ch;

    return iso;
}

double NtupleMaker::GetEffectiveAreaForMuon(double eta) {
	double effective_area{1.};
	if      ( fabs(eta) >= 0.  || fabs(eta) < 0.8 ) effective_area = 0.0735;
	else if ( fabs(eta) >= 0.8 || fabs(eta) < 1.3 ) effective_area = 0.0619;
	else if ( fabs(eta) >= 1.3 || fabs(eta) < 2.0 ) effective_area = 0.0465;
	else if ( fabs(eta) >= 2.0 || fabs(eta) < 2.2 ) effective_area = 0.0433;
	else if ( fabs(eta) >= 2.2 || fabs(eta) < 2.5 ) effective_area = 0.0577;

	return effective_area;
}

double NtupleMaker::GetEffectiveAreaForElectron(double eta) {
	double effective_area{1.};
	if      ( fabs(eta) >= 0.    || fabs(eta) < 1.    ) effective_area = 0.1752;
	else if ( fabs(eta) >= 1.	 || fabs(eta) < 1.479 ) effective_area = 0.1862;
	else if ( fabs(eta) >= 1.479 || fabs(eta) < 2.0   ) effective_area = 0.1411;
	else if ( fabs(eta) >= 2.0   || fabs(eta) < 2.2   ) effective_area = 0.1534;
	else if ( fabs(eta) >= 2.2   || fabs(eta) < 2.3   ) effective_area = 0.1903;
	else if ( fabs(eta) >= 2.3   || fabs(eta) < 2.4   ) effective_area = 0.2243;
	else if ( fabs(eta) >= 2.4   || fabs(eta) < 2.5   ) effective_area = 0.2687;

	return effective_area;
}
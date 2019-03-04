#include "Physics/NtupleMaker/interface/NtupleMaker.h"

void FillWithLocalTracks(const edm::Event&)
{
    edm::Handle<std::vector<CTPPSLocalTrackLite>> local_tracks;
    event.getByToken(local_tracks_token_, local_tracks);

    event_.num_local_tracks = local_tracks->size();

    auto index = 0;
    for (const auto& local_track : local_tracks)
    {
        event_.local_track_rpId[index] = local_track.getRPId();
        event_.local_track_x[index] = local_track.getX();
        event_.local_track_x_unc[index] = local_track.getXUnc();
        event_.local_track_y[index] = local_track.getY();
        event_.local_track_y_unc[index] = local_track.getYUnc();
        event_.local_track_tx[index] = local_track.getTx();
        event_.local_track_tx_unc[index] = local_track.getTxUnc();
        event_.local_track_ty[index] = local_track.getTy();
        event_.local_track_ty_unc[index] = local_track.getTyUnc();
        event_.local_track_chiSquaredOverNDF[index] = local_track.getChiSquaredOverNDF();

        ++index;
    }
}
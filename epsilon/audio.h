#ifndef EPSILON_AUDIO_H
#define EPSILON_AUDIO_H


typedef struct {
	MIX_Audio* data;
	MIX_Track* track;
} audio;

 audio * selected_audio = NULL;


 audio* create_audio(const char* path, bool predecode) {
	 audio* aud = SDL_malloc(sizeof(audio));
	 if (!aud) return NULL;

	 aud->data  = NULL;
	 aud->track = NULL;

	 aud->data = MIX_LoadAudio(selected_window->mixer, path, predecode);
	 if (!aud->data) {
		 SDL_Log("MIX_LoadAudio failed for '%s': %s", path, SDL_GetError());
		 SDL_free(aud);
		 return NULL;
	 }

	 aud->track = MIX_CreateTrack(selected_window->mixer);
	 if (!aud->track) {
		 SDL_Log("MIX_CreateTrack failed: %s", SDL_GetError());
		 MIX_DestroyAudio(aud->data);
		 SDL_free(aud);
		 return NULL;
	 }

	 MIX_SetTrackAudio(aud->track, aud->data);
	 selected_audio = aud;
	 return aud;
 }


void destroy_audio(){
	MIX_DestroyAudio(selected_audio->data);
	MIX_DestroyTrack(selected_audio->track);

	free(selected_audio);

	selected_audio=NULL;
}



void play_audio() {
	// Guard against NULL selected_audio first
	if (!selected_audio || !selected_audio->data) return;

	if (!selected_audio->track) {
		selected_audio->track = MIX_CreateTrack(selected_window->mixer);
		if (!selected_audio->track) {
			SDL_Log("Failed to create track: %s", SDL_GetError());
			return;
		}
		// Only set track audio if the track was just (re)created
		MIX_SetTrackAudio(selected_audio->track, selected_audio->data);
	}

	MIX_SetTrackLoops(selected_audio->track, -1); // -1 = infinite, 0 = once
	MIX_PlayTrack(selected_audio->track, 0);
}



void pause_audio() {
	if (!selected_audio->track) return;
	MIX_PauseTrack(selected_audio->track);
}



void stop_audio() {
	if (!selected_audio->track) return;
	MIX_PauseTrack(selected_audio->track);
	MIX_SetTrackPlaybackPosition(selected_audio->track, 0);

}



void resume_audio() {
	if (!selected_audio->track) return;
	MIX_ResumeTrack(selected_audio->track);
}



void set_speed(float speed) {
	if (!selected_audio->track) return;
	MIX_SetTrackFrequencyRatio(selected_audio->track, speed);
}



void set_volume(float volume) {
	if (!selected_audio || !selected_audio->track) return;

	MIX_SetTrackGain(selected_audio->track, volume);
}



void destroy_audio() {
	if (selected_audio->track) {
		MIX_DestroyTrack(selected_audio->track);
	}
	if (selected_audio->data) {
		MIX_DestroyAudio(selected_audio->data);
	}
}



bool is_playing() {
	if (!selected_audio || !selected_audio->track) return false;
	return MIX_TrackPlaying(selected_audio->track);
}

#endif

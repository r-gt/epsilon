#ifndef EPSILON_AUDIO_H
#define EPSILON_AUDIO_H


typedef struct {
	MIX_Audio* data;
	MIX_Track* track;
} audio;

audio * selected_audio = NULL;



audio* create_audio(const char* path, bool predecode) {
	audio* aud;

	aud        = SDL_malloc(sizeof(audio));
	aud->data  = NULL;
	aud->track = NULL;

	aud->data  = MIX_LoadAudio(selected_window->mixer, path, predecode);
	aud->track = MIX_CreateTrack(selected_window->mixer);

	if (!aud->data || !aud->track) {
		SDL_Log("Failed to load audio: %s | %s", path, SDL_GetError());
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



void audio_play() {

	if (!selected_audio->data) return;

	if(!selected_audio->track)
	selected_audio->track = MIX_CreateTrack(selected_window->mixer);

	if (!selected_audio->track) {
		SDL_Log("Failed to create track: %s", SDL_GetError());
		return ;
	}

	MIX_SetTrackAudio(selected_audio->track, selected_audio->data);
	MIX_SetTrackLoops(selected_audio->track, 1);
	MIX_PlayTrack(selected_audio->track, 0);
}



void audio_pause() {
	if (!selected_audio->track) return;
	MIX_PauseTrack(selected_audio->track);
}



void audio_resume() {
	if (!selected_audio->track) return;
	MIX_ResumeTrack(selected_audio->track);
}



void audio_set_speed(float speed) {
	if (!selected_audio->track) return;
	MIX_SetTrackFrequencyRatio(selected_audio->track, speed);
}



void audio_unload() {
	if (selected_audio->track) {
		MIX_DestroyTrack(selected_audio->track);
	}
	if (selected_audio->data) {
		MIX_DestroyAudio(selected_audio->data);
	}
}



bool audio_is_playing() {
	if (!selected_audio || !selected_audio->track) return false;
	return MIX_TrackPlaying(selected_audio->track);
}

#endif

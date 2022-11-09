#include "Audio.h"

void Audio::play() {	//Just plays the music track; realistically until I add music options pause will never be called
	music.play();
	music.setVolume(30.f);
	music.setLoop(true);
	playing = true;
};

void Audio::pause() {
	music.pause();
	playing = false;
};
#pragma once
#include <SFML\Audio.hpp>
class Audio {
private:
	sf::Music music;
	bool playing = false;
public:
	Audio() { music.openFromFile("./files/audio/whine.wav"); };
	void play();
	bool isPlaying() { return playing; };
	void pause();
};


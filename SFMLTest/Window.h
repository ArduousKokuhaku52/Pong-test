#pragma once
#include <SFML\Graphics.hpp>

class Window {
private:
	sf::RenderWindow window;
public:
	bool isRunning();
	void pollEvent();
	void gameEvent();
	void gameUpdate();
};


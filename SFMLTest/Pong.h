#pragma once
#include "Object.h"
class Pong : public Object {
private:
	sf::RectangleShape pong;
public:
	Pong(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, float x, float y, float w, float h, float vx, float vy);
	sf::RectangleShape getObject() { return pong; };
	void update();
	void reset();
	void checkBounds(int& score);
};


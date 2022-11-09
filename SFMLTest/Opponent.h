#pragma once
#include "Object.h"
class Opponent : public Object {
private:
	sf::RectangleShape opponent;
public:
	Opponent(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, float x, float y, float w, float h);
	sf::RectangleShape getObject() { return opponent; };
	void update(float x, float y);
};


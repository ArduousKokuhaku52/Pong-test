#pragma once
#include "Object.h"
class Player : public Object {
private:
	sf::RectangleShape player;
	bool boosting = false;
public:
	Player(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, float x, float y, float w, float h);
	sf::RectangleShape getObject() { return player; };
	void isBoosting(bool boost) { boosting = boost; };
	void update();
};


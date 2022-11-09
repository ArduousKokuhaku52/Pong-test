#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Pong.h"
#include "Opponent.h"
class Events {
public:
	void collision(Player& player, Pong& pong, Opponent& opponent, int& interval, int& score);
	void pollEvent(sf::RenderWindow& window, Player& player);
};


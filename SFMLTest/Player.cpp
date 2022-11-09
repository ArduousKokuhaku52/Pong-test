#include "Player.h"

Player::Player(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, float x, float y, float w, float h) {
	m_color = sf::Color(r, g, b);
	this->x = x;
	this->y = y;
	player.setSize(sf::Vector2f(w, h));
	player.setFillColor(m_color);
	player.setPosition(x, y);
	m_bounds = player.getGlobalBounds();
};

void Player::update() {
	//Holding LShift increases velocity by 1.5 times
	if (boosting) {
		x += 1.5f * velx;
		y += 1.5f * vely;
	}
	else {
		x += velx;
		y += vely;
	}

	//Keeps player in bounds of window
	if (m_bounds.top < 0) {
		y = 0;
	}
	else if (m_bounds.top + 50 > 600) {
		y = 550;
	}

	m_bounds = player.getGlobalBounds();
	player.setPosition(x, y);
};

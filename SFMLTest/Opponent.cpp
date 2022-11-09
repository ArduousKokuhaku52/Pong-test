#include "Opponent.h"

Opponent::Opponent(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, float x, float y, float w, float h) {
	m_color = sf::Color(r, g, b);
	this->x = x;
	this->y = y;
	opponent.setSize(sf::Vector2f(w, h));
	opponent.setFillColor(m_color);
	opponent.setPosition(x, y);
	m_bounds = opponent.getGlobalBounds();
};

void Opponent::update(float x, float y) {
	//"AI" code; when pong is on this side it takes its y position and changes its velocity accordingly
	if (x > 400) {
		if (y > this->y) {
			vely = .10f;
		}
		else if (y < this->y) {
			vely = -.10f;
		}
	}
	else {
		if (this->y < 250) {
			vely = .09f;
		}
		else if (this->y > 250) {
			vely = -.09f;
		}
	}

	this->y += vely;	//Updates y position

	//Keeps opponent in bounds of window
	if (m_bounds.top < 0) {
		this->y = 0;
	}
	else if (m_bounds.top + 50 > 600) {
		this->y = 550;
	}

	m_bounds = opponent.getGlobalBounds();
	opponent.setPosition(this->x, this->y);
};
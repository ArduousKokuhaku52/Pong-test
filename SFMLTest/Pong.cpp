#include "Pong.h"

Pong::Pong(sf::Uint8 r, sf::Uint8 g, sf::Uint8 b, float x, float y, float w, float h, float vx, float vy) {
	m_color = sf::Color(r, g, b);
	this->x = x;
	this->y = y;
	this->velx = vx;
	this->vely = vy;
	pong.setSize(sf::Vector2f(w, h));
	pong.setFillColor(m_color);
	pong.setPosition(x, y);
	m_bounds = pong.getGlobalBounds();
};

void Pong::update() {	//Updates position based on velocity
	x += velx;
	y += vely;
	m_bounds = pong.getGlobalBounds();
	pong.setPosition(x, y);
};

void Pong::reset(int scored) {	//Resets to the middle; might change it later to do different things depending on who scores
	if (scored == 0) {
		x = 390.f;
		y = 280.f;
		velx = -.05f;
		vely = .05f;
		pong.setPosition(x, y);
	}
	else {
		x = 390.f;
		y = 280.f;
		velx = .05f;
		vely = .05f;
		pong.setPosition(x, y);
	}
};

void Pong::checkBounds(int& score) {
	if (m_bounds.top < 0 || m_bounds.top + 10 > 600) {	//Checks collision for top and bottom of the screen
		if (m_bounds.top < 0) {
			y = 0;
			pong.setPosition(x, y);
			vely = -vely;
		}
		else {
			y = 590;
			pong.setPosition(x, y);
			vely = -vely;
		}
	}
	if (m_bounds.left < -5 || m_bounds.left > 800) {	//Resets score and pong if either player or opponent scores
		if (m_bounds.left < -5) {
			reset(0);	//If opponent scores pong goes toward player
		}
		else {
			reset(1);	//If player scores pong goes toward opponent
		}
		score = 1;
	}
};
#pragma once
#include <SFML\Graphics.hpp>
class Object {
protected:
	sf::FloatRect m_bounds;
	sf::Color m_color;
	float x;
	float y;
	float velx = 0;
	float vely = 0;
public:
	sf::FloatRect getBounds() { return m_bounds; };
	sf::Color getColor() { return m_color; };
	void setvelx(float velx) { this->velx = velx; };
	void setvely(float vely) { this->vely = vely; };
	float getvelx() { return velx; };
	float getvely() { return vely; };
	float getx() { return x; };
	float gety() { return y; };
	virtual sf::RectangleShape getObject() = 0;
};


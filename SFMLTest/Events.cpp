#include "Events.h"

void Events::collision(Player& player, Pong& pong, Opponent& opponent, int& interval, int& score) {
	if (player.getBounds().intersects(pong.getBounds()) || opponent.getBounds().intersects(pong.getBounds())) {
		if (interval > 1000) {
			float py = player.getvely();
			float x = pong.getvelx();
			float y = pong.getvely();
			
			//Reverses y direction if player hits it going in the opposite y direction
			if (py < 0 && y > 0) {
				y = -y;
			}
			else if (py > 0 && y < 0) {
				y = -y;
			}

			//Increases speed everytime someone hits it
			if (x < 0) {
				x -= .003f;
				y -= .01f;
			}
			else {
				x += .003f;
				y += .01f;
			}

			pong.setvelx(-x);
			pong.setvely(y);
			interval = 0;
			score++;
		}
	}
};

void Events::pollEvent(sf::RenderWindow& window, Player& player) {	//Window & keyboard event handler
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.setvely(-.12f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.setvely(.12f);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) player.isBoosting(true);
			break;
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::W) player.setvely(0.f);
			if (event.key.code == sf::Keyboard::S) player.setvely(0.f);
			if (event.key.code == sf::Keyboard::LShift) player.isBoosting(false);
			break;
		default:
			break;
		}
	}
};
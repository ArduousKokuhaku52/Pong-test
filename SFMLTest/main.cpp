#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Object.h"
#include "Player.h"
#include "Events.h"
#include "Opponent.h"
#include "Pong.h"
#include "Audio.h"

void render(sf::RenderWindow& window, Object* objects[], sf::Text& text) {
	window.clear(sf::Color::Black);
	for (int i = 0; i < 3; i++) {
		window.draw(objects[i]->getObject());
	}
	window.draw(text);
	window.display();
};

int wmain() {

	sf::Text text;
	sf::Font font;
	font.loadFromFile("./files/fonts/arial.ttf");
	text.setFont(font);

	int interval = 0;
	int streak = 0;
	int score = 1;
	std::string string;

	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	Player player(100, 250, 50, 5.f, 250.f, 10.f, 50.f);
	Pong pong(255, 255, 255, 390.f, 280.f, 10.f, 10.f, -.05f, .05f);
	Opponent opponent(100, 250, 50, 785.f, 250.f, 10.f, 50.f);
	Audio music;
	Events gameEvents;

	Object* objects[3]{ &player, &pong, &opponent };

	text.setString("score: ");
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);

	while (window.isOpen()) {
		if (!music.isPlaying()) {
			music.play();
		}

		//Checks keyboard inputs
		gameEvents.pollEvent(window, player);

		//Checks for a collision with the player, opponent, or the walls
		gameEvents.collision(player, pong, opponent, interval, score);
		pong.checkBounds(score);

		//Updates all the positions
		player.update();
		pong.update();
		opponent.update(pong.getx(), pong.gety());

		//Updates score string
		string = "score: " + std::to_string(score/2);
		text.setString(string);

		//Renders the window
		render(window, objects, text);

		//Using this to make sure pong has enough time to leave the player/opponents bounds
		interval++;
	}

	return 0;
}
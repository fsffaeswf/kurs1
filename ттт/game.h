#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <vector>
#include<Windows.h>
#include "player.h"
#include "background.h"
#include "meteor.h"

class Game {
private:
	sf::RenderWindow window;
	Player player;
	Background background;
	std::vector<Meteor*> meteors;
public:
	void spawnMeteors(size_t n) {
		for (int i = 0; i < n; i++) {
			float x;
			float speedx;
			int choice = rand() % 2147483647;
			if (choice < 2147483647 / 2) {
				x = -50.f;
				 speedx = meteor_speed;
			}
			else {
				x = WINDOW_WIDTH + 50.f;
				 speedx = -meteor_speed;
			}


			float y;
			choice = rand() % 4;
			if (choice == 1) { y = 0; }
			else if (choice == 2) { y = 270.f; }
			else if (choice == 3) { y = 540.f; }
			else if (choice == 4) { y = 810.f; }
			Meteor* m = new Meteor( sf::Vector2f{ x, y }, sf::Vector2f{ speedx,0});
			meteors.push_back(m);
		}
	}

	Game() {
		window.create(sf::VideoMode::getDesktopMode(), "SFML works!", sf::Style::Fullscreen);
		spawnMeteors(15);
		window.setFramerateLimit(FPS);

	}

	void chek_events() {
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				
				window.close();
		}
	}


	void update() {
		player.update();
		background.update();
		for (int i = 0; i < meteors.size(); i++) {
			meteors.at(i)->update();
		}
	}


	void chek_collisons() {
	}
	void draw() {
		window.clear();
		
		background.draw(window);
		for (int i = 0; i < meteors.size(); i++) {
			window.draw(meteors.at(i)->getSprite());
		}
		player.draw(window);
		window.display();
	}

	void play() {
		while (window.isOpen())
		{
			chek_events();
			update();
			chek_collisons();
			draw();
		}
	}
};
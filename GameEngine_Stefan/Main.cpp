#include "sfml/graphics.hpp"

int main(int argc, char* args[]) {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");

	//run the program as long as the window is gone

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			//close requested event
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}

	return 0;
}
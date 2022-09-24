#include "sfml/graphics.hpp"
#include "Engine.h"

int main(int argc, char* args[]) {
	//declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();
	//create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");
	//pass window refrence to the engine and start
	gameEngine.Start(& window); //passing in the address of the window
	

	return 0;
}
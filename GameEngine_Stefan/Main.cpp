#include "sfml/graphics.hpp"
#include "Engine.h"

int main(int argc, char* args[]) {
	//declare and get instance of singleton
	Engine& gameEngine = Engine::GetInstance();
	//create the window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");

	//create the world and attach entities and systems to it
	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* stickFigure; 

	//add systems to the engine
	gameEngine.AddSystem(new RenderingSystem());

	//create & assign 250 entities to the world
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			stickFigure = gameEngine.world->create();
			//assign components to entities after creation
			stickFigure->assign<Transform>(x * 25, y * 32);
			stickFigure->assign<Sprite2D>("../Debug/Pics/hero.png");
			std::cout << stickFigure->getEntityId() << " is the entity id." << std::endl;
		}
	}

	//pass window refrence to the engine and start
	gameEngine.Start(& window); //passing in the address of the window
	

	return 0;
}
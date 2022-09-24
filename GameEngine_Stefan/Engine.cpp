#include "Engine.h"

void Engine::Start(sf::RenderWindow* win)
{
	this->window = win;
	//run the program as long as the window is gone

	while (window->isOpen()) {

	}
}

Engine::Engine()
{
	bQuit = false;
}

Engine::~Engine() = default; // stays as standard built-in deconstructor

void Engine::Update()
{
	sf::Event event;
	while (window->pollEvent(event)) {
		//close requested event
		if (event.type == sf::Event::Closed) {
			window->close();
		}
	}
}

Engine& Engine::GetInstance() 
{
	static Engine instance;
	return instance;
}

void Engine::AddSystem(ECS::EntitySystem* newSys)
{
	world->registerSystem(newSys);
	world->enableSystem(newSys);
}

#include "Engine.h"

void Engine::Start(sf::RenderWindow* win)
{
	this->window = win;
	mainCamera = new MainCamera(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2));

	pauseMenu = new PauseMenu(win);

	//run the program as long as the window is gone

	while (window->isOpen()) {
		Update();
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

		this->pauseMenu->Update(event, 10.0f, this->window);
	}

	world->tick(10.0f);

	mainCamera->Update(world, 10.0f, window);

	if (States::GetPausedState()) {
		this->onGameInactiveState();
	}
}

void Engine::onGameInactiveState()
{
	pauseMenu->Render(this->window, 10.0f, this->mainCamera->cameraView.getCenter());
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

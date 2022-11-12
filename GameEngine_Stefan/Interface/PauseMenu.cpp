#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow* window)
{
	States::SetPausedState(false);
	this->InitButtons();
}

void PauseMenu::Update(sf::Event event, float deltaTime, sf::RenderWindow* window)
{
	if (event.type == sf::Event::KeyPressed) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			States::SetPausedState(!States::GetPausedState());
		}
	}

	if (States::GetPausedState()) {
		ButtonMap::GetMap()["RESUME"]->Update(event, deltaTime);
		ButtonMap::GetMap()["SAVE"]->Update(event, deltaTime);
		ButtonMap::GetMap()["QUIT"]->Update(event, deltaTime);
		ButtonMap::GetMap()["LOAD"]->Update(event, deltaTime);

		if (ButtonMap::GetMap()["RESUME"]->bClicked) {
			States::SetPausedState(! States::GetPausedState());
			ButtonMap::GetMap()["RESUME"]->bClicked = false;
		}
		if (ButtonMap::GetMap()["QUIT"]->bClicked) {
			this->Quit(window);
			ButtonMap::GetMap()["RESUME"]->bClicked = false;
		}
	}
}

void PauseMenu::Render(sf::RenderWindow* window, float deltaTime, sf::Vector2f resumePosition)
{
	sf::Font trebuchet;
	trebuchet.loadFromFile("../Debug/Fonts/trebuc.TTF");
	sf::Vector2f sizeOffset = sf::Vector2f(
		ButtonMap::GetMap()["RESUME"]->buttonBG.getSize().x / 2.0f,
		ButtonMap::GetMap()["RESUME"]->buttonBG.getSize().y / 2.0f
	);

	ButtonMap::GetMap()["RESUME"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -80) - sizeOffset);
	ButtonMap::GetMap()["RESUME"]->buttonText.setFont(trebuchet);
	ButtonMap::GetMap()["RESUME"]->buttonText.setPosition(ButtonMap::GetMap()["RESUME"]->buttonBG.getPosition());
	ButtonMap::GetMap()["RESUME"]->HighlightButton(window);
	ButtonMap::GetMap()["RESUME"]->Render(window, deltaTime);

	ButtonMap::GetMap()["LOAD"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, -40) - sizeOffset);
	ButtonMap::GetMap()["LOAD"]->buttonText.setFont(trebuchet);
	ButtonMap::GetMap()["LOAD"]->buttonText.setPosition(ButtonMap::GetMap()["LOAD"]->buttonBG.getPosition());
	ButtonMap::GetMap()["LOAD"]->HighlightButton(window);
	ButtonMap::GetMap()["LOAD"]->Render(window, deltaTime);
	
	ButtonMap::GetMap()["SAVE"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 0) - sizeOffset);
	ButtonMap::GetMap()["SAVE"]->buttonText.setFont(trebuchet);
	ButtonMap::GetMap()["SAVE"]->buttonText.setPosition(ButtonMap::GetMap()["SAVE"]->buttonBG.getPosition());
	ButtonMap::GetMap()["SAVE"]->HighlightButton(window);
	ButtonMap::GetMap()["SAVE"]->Render(window, deltaTime);

	ButtonMap::GetMap()["QUIT"]->buttonBG.setPosition(resumePosition + sf::Vector2f(0, 40) - sizeOffset);
	ButtonMap::GetMap()["QUIT"]->buttonText.setFont(trebuchet);
	ButtonMap::GetMap()["QUIT"]->buttonText.setPosition(ButtonMap::GetMap()["QUIT"]->buttonBG.getPosition());
	ButtonMap::GetMap()["QUIT"]->HighlightButton(window);
	ButtonMap::GetMap()["QUIT"]->Render(window, deltaTime);

	window->display();
}

void PauseMenu::InitButtons()
{
	sf::Vector2f size(125, 35);

	ButtonMap::GetMap().insert(
		{
			"RESUME", new Button(size, sf::Color(100, 100, 100, 255), "RESUME GAME")
		}
	);
	ButtonMap::GetMap().insert(
		{
			"LOAD", new Button(size, sf::Color(100, 100, 100, 255), "LOAD TILE MAP")
		}
	);
	ButtonMap::GetMap().insert(
		{
			"SAVE", new Button(size, sf::Color(100, 100, 100, 255), "SAVE TILE MAP")
		}
	);
	ButtonMap::GetMap().insert(
		{
			"QUIT", new Button(size, sf::Color(100, 100, 100, 255), "QUIT GAME")
		}
	);
}

void PauseMenu::Quit(sf::RenderWindow* window)
{
	window->close();
}

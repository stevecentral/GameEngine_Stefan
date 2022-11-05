#include "MainCamera.h"

MainCamera::MainCamera(sf::Vector2f pivot)
{
	cameraView.setCenter(pivot);
}

void MainCamera::Update(ECS::World* world, float deltaTime, sf::RenderWindow* window)
{
	float cameraMoveSpeed = 0.1f;

	cameraView.setSize(window->getSize().x, window->getSize().y);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		cameraView.move(cameraMoveSpeed * deltaTime, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		cameraView.move(-cameraMoveSpeed * deltaTime, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		cameraView.move(0, cameraMoveSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		cameraView.move(0, -cameraMoveSpeed * deltaTime);
	}
	window->setView(cameraView);
}

#pragma once
#include <iostream>
#include "sfml/Graphics.hpp"
#include "ECS.h"
#include "Components.h"
#include "Systems/RenderingSystem.h"
#include "Systems/AnimationSystem.h"
#include "Systems/MovementSystem.h"
#include "Systems/InputSystem.h"

class Engine
{
public:
	sf::RenderWindow* window = nullptr;
	ECS::World* world = nullptr;

private:
	bool bQuit;

public:
	void Start(sf::RenderWindow* win);
	static Engine& GetInstance();
	void AddSystem(ECS::EntitySystem* newSys);

private:
	Engine();
	//Required to prevent the refrence from being copied, moved or assigned
	Engine(Engine& copy); // hide copy constructor
	Engine(Engine&& other); // hide move constructor
	Engine& operator=(Engine& copy); // hide assigned operator

	~Engine();
	void Update();
};


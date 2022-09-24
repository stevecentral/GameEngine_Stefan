#pragma once
#include <iostream>
#include "sfml/Graphics.hpp"

class Engine
{
public:
	sf::RenderWindow* window;

private:
	bool bQuit;

public:
	void Start(sf::RenderWindow* win);
	static Engine& GetInstance();

private:
	Engine();
	//Required to prevent the refrence from being copied, moved or assigned
	Engine(Engine& copy); // hide copy constructor
	Engine(Engine&& other); // hide move constructor
	Engine& operator=(Engine& copy); // hide assigned operator

	~Engine();
	void Update();
};


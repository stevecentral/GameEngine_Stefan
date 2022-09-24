#pragma once
#include "Engine.h"

struct Transform
{
public:
	ECS_DECLARE_TYPE; //macros
	float xPos;
	float yPos;

	Transform(float newX, float newY): xPos(newX), yPos(newY) { //same thing as this->xPos = newX


	}
	
};
ECS_DEFINE_TYPE(Transform);

struct Sprite2D
{
public:
	ECS_DECLARE_TYPE;

	sf::Sprite picture;
	std::string texture;
	int width, height;

	Sprite2D(std::string filePath) : texture(filePath) {

	}
};
ECS_DEFINE_TYPE(Sprite2D);
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

struct Animator
{
public:
	ECS_DECLARE_TYPE;

	int spriteWidth, spriteHeight;
	int currentColumn, currentRow, totalColumns, totalRows;
	float currentTime, nexFrameTime;
	bool bFacingRight;

	Animator(int newWidth, int newHeight, float timeBetweenFrames, int columns, int rows) {
		this->spriteWidth = newWidth;
		this->spriteHeight = newHeight;
		this->currentColumn = 0;
		this->currentRow = 0;
		this->totalColumns = columns;
		this->totalRows = rows;
		this->nexFrameTime = timeBetweenFrames;
		this->currentTime = 0;
		this->bFacingRight = true;
	}
};
ECS_DEFINE_TYPE(Animator);
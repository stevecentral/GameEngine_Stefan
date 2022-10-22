#pragma once
#include "Engine.h"

struct Transform
{
public:
	ECS_DECLARE_TYPE; //macros
	float xPos, yPos;
	float rotation;
	float xSpeed, ySpeed, xSpeedMod, ySpeedMod;

	Transform(float newX, float newY, float newXSpeed = 0.0f, float newYSpeed = 0.0f, float rotation = 0.0f)
		: xPos(newX), yPos(newY) { //same thing as this->xPos = newX

		this->xSpeed = 0.0f;
		this->ySpeed = 0.0f;
		this->xSpeedMod = newXSpeed;
		this->ySpeedMod = newYSpeed;
		this->rotation = rotation;
	}

	void Move(){
		this->xPos += this->xSpeed;
		this->yPos += this->ySpeed;
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

struct InputController {
public:
	ECS_DECLARE_TYPE;
	bool bInputActive;
	bool w, a, s, d, left, right, up, down, space;

	InputController() {
		std::memset(this, false, sizeof(InputController));
		bInputActive = true;
	}
};
ECS_DEFINE_TYPE(InputController);

struct BoxCollider {
public:
	ECS_DECLARE_TYPE;
	int leftEdge, rightEdge, topEdge, bottomEdge;

	BoxCollider() {
		std::memset(this, 0, sizeof(BoxCollider));
	}

	void Update(int x, int y, int width, int height) {
		this->leftEdge = x;
		this->rightEdge = x + width;
		this->topEdge = y;
		this->bottomEdge = y + height;
	}
};
ECS_DEFINE_TYPE(BoxCollider);
#pragma once
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>

class Tile
{
public:
	bool bColliding;
	sf::RectangleShape shape;

	Tile() = default;
	Tile(float xPos, float yPos, float gridSizeF, bool bColliding);
	~Tile() = default;

	void Render(sf::RenderTarget& target);
	const bool& GetCollision() const;
	const sf::Vector2f& GetPosition() const;
	std::string ToString();
};


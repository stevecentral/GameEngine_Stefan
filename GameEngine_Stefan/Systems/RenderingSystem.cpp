#include "RenderingSystem.h"

RenderingSystem::RenderingSystem() = default;

RenderingSystem::~RenderingSystem() = default;

void RenderingSystem::tick(ECS::World* world, float deltaTime)
{
	//clear before drawing all textures
	Engine::GetInstance().window->clear();

	world->each <Transform, Sprite2D>(
		[&](ECS::Entity* entity,	//[&] passes in the address
			ECS::ComponentHandle <Transform> transform,
			ECS::ComponentHandle <Sprite2D> sprite2D
			) -> void
		{
			//check if an entity has their texture already loaded
			if (textureMap.count(sprite2D->texture) < 1) {
				textureMap[sprite2D->texture] = LoadTexture(sprite2D->texture);
			}

			//if no texture is found, then add a texture to the map
			if (sprite2D->picture.getTexture() == nullptr) {
				sprite2D->picture.setTexture(*textureMap[sprite2D->texture]);
				sprite2D->width = sprite2D->picture.getGlobalBounds().width;
				sprite2D->height = sprite2D->picture.getGlobalBounds().height;
			}

			//update and draw to the screen
			sprite2D->picture.setPosition(transform->xPos, transform->yPos);
			Engine::GetInstance().window->draw(sprite2D->picture);
		});

	//display updates
	Engine::GetInstance().window->display();
}

sf::Texture* RenderingSystem::LoadTexture(std::string texturePath)
{
	sf::Texture* _texture = new sf::Texture();
	//if the texture is not found
	if (! _texture->loadFromFile(texturePath)) {
		//prints out a line
		std::cerr << "error: unable to load image " << texturePath << "\nIs this image in the correct directory?" << std::endl;	
		system("pause");
		exit(EXIT_FAILURE);
	}
	return _texture;
}

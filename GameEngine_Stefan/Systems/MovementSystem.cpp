#include "MovementSystem.h"

void MovementSystem::tick(ECS::World* world, float deltaTime)
{
	world->each <InputController, Sprite2D, Transform>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle <InputController> input,
			ECS::ComponentHandle <Sprite2D> sprite,
			ECS::ComponentHandle <Transform> transform)
		->void {
			//sprite->picture.setOrigin(sf::Vector2f(sprite->width / 2, sprite->height / 2));
			//ECS::ComponentHandle <InputController> input = entity->get<InputController>();
			if (input->bInputActive == true)
			{
				if (input->s)
				{
					transform->ySpeed =+ transform->ySpeedMod;
					transform->Move();
				}
				if (input->w)
				{
					transform->ySpeed =- transform->ySpeedMod;
					transform->Move();
				}
				if (input->d)
				{
					transform->xSpeed =+ transform->xSpeedMod;
					transform->Move();
				}
				if (input->a)
				{
					transform->xSpeed =- transform->xSpeedMod;
					transform->Move();
				}
				
			}
		});
}

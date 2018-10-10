#pragma once


#include "../Game.h"
#include "CompHandler.h"
#include "Components.h"

class KeyboardHandler : public Component
{
	public:
		TransformComponent *transform;
		SpriteComponent *sprite;
	

		void init() override
		{
			transform = &entity->getComponent<TransformComponent>();
			sprite = &entity->getComponent<SpriteComponent>();
		}

		void update() override
		{
			int tempx = Game::event.motion.x;
			int tempy = Game::event.motion.y;

			if (Game::event.type == SDL_MOUSEBUTTONDOWN)
			{
					switch (Game::event.button.button)
					{
					case SDL_BUTTON_LEFT:
						transform->move(tempx, tempy);
						sprite->play("WalkU");
						break;
					case SDLK_a:
						transform->velocity.x = -1;
						sprite->play("WalkR");
						sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
						break;
					case SDLK_s:
						transform->velocity.y = 1;
						sprite->play("WalkU");
						sprite->spriteFlip = SDL_FLIP_VERTICAL;
						break;
					case SDLK_d:
						transform->velocity.x = 1;
						sprite->play("WalkR");
						break;
					default:
						break;
				}
			}


			/*if (Game::event.type == SDL_KEYDOWN)
			{
				switch (Game::event.key.keysym.sym)
				{
				case SDLK_w:
					transform->velocity.y = -1;
					sprite->play("WalkU");
					break;
				case SDLK_a:
					transform->velocity.x = -1;
					sprite->play("WalkR");
					sprite->spriteFlip = SDL_FLIP_HORIZONTAL;
					break;
				case SDLK_s:
					transform->velocity.y = 1;
					sprite->play("WalkU");
					sprite->spriteFlip = SDL_FLIP_VERTICAL;
					break;
				case SDLK_d:
					transform->velocity.x = 1;
					sprite->play("WalkR");
					break;
				default:
					break;
				}
			}

			if (Game::event.type == SDL_KEYUP)
			{
				switch (Game::event.key.keysym.sym)
				{
				case SDLK_w:
					transform->velocity.y = 0;
					sprite->play("Idle");
					break;
				case SDLK_a:
					transform->velocity.x = 0;
					sprite->play("Idle");
					sprite->spriteFlip = SDL_FLIP_NONE;
					break;
				case SDLK_s:
					transform->velocity.y = 0;
					sprite->play("Idle");
					sprite->spriteFlip = SDL_FLIP_NONE;
					break;
				case SDLK_d:
					transform->velocity.x = 0;
					sprite->play("Idle");
					break;
				default:
					break;
				}

			}*/
		}

};



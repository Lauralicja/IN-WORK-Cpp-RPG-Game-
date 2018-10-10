#pragma once

#include "Components.h"
#include "../TexHandler.h"
#include "SDL.h"
#include "Animation.h"
#include <map>

class SpriteComponent : public Component
{
	private:
		TransformComponent *transform;
		SDL_Texture *texture;
		SDL_Rect srcRect, destRect;

		bool animated = false;
		int frames = 0;
		int speed = 100;

	public:

		int animIndex = 0;
		std::map<const char*, Animation> animations;

		SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

		SpriteComponent() = default;
		SpriteComponent(const char *path)
		{
			setTex(path);
		}
		SpriteComponent(const char *path, bool isAnimated)
		{
			animated = isAnimated;

			Animation idle = Animation(0, 3, 100);
			Animation walkR = Animation(1, 3, 100);
			Animation walkU = Animation(2, 3, 100);



			animations.emplace("Idle", idle);
			animations.emplace("WalkR", walkR);
			animations.emplace("WalkU", walkU);


			play("Idle");
			setTex(path);
		}

		~SpriteComponent()
		{
			SDL_DestroyTexture(texture);
		}


		void setTex(const char* path)
		{
			texture = TexHandler::LoadTex(path);
		}

		void init() override
		{
			transform = &entity->getComponent<TransformComponent>();

			srcRect.x = srcRect.y = 0;
			srcRect.w = transform->width;
			srcRect.h = transform->height;
		}

		void update() override
		{

			if (animated)
			{
				srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
			}

			srcRect.y = animIndex * transform->height;

			destRect.x = static_cast<int>(transform->position.x);
			destRect.y = static_cast<int>(transform->position.y);
			destRect.w = transform->width * transform->scale;
			destRect.h = transform->height * transform->scale;
		}

		void draw() override
		{
			TexHandler::Draw(texture, srcRect, destRect, spriteFlip);
		}

		void destroy() override
		{
			TexHandler::DestroyTex(texture);
		}

		void play(const char* animName)
		{
			frames = animations[animName].frames;
			animIndex = animations[animName].index;
			speed = animations[animName].speed;
		}
};
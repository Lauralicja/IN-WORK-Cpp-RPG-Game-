#pragma once
#include "Components.h"
#include "../Vector2D.h"


class TransformComponent : public Component
{
	
public:

	Vector2D position;
	Vector2D velocity;

	int height = 64;
	int width = 64;
	int scale = 1;

	int speed = 3;


	TransformComponent() // domyslny
	{
		position.Zero();
	}

	TransformComponent(int sc) // + skala
	{
		position.Zero();
		scale = sc;
	}

	TransformComponent(float x, float y, int h, int w, int sc)
	{
		position.x = x; // x, y, wysokosc bloku, szerokosc bloku, skala
		position.y = y; 
		height = h;		
		width = w;		
		scale = sc;
	}

	TransformComponent(float x, float y) // x, y 
	{
		position.x = x;
		position.y = y;
	}

	void init() override
	{
		velocity.Zero();
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

	void move(int destx, int desty)
	{
		int d, dx, dy, ai, bi, xi, yi;

		if (position.x < destx)
		{
			velocity.x = 1;
			xi = 1;
			dx = destx - position.x;
		}
		else
		{
			velocity.x = -1;
			xi = -1;
			dx = position.x - destx;
		}

		if (position.y < desty)
		{
			velocity.y = 1;
			yi = 1;
			dy = desty - position.y;
		}
		else
		{
			velocity.y = -1;
			yi = -1;
			dy = position.y - desty;
		}
		
		if (dx > dy) {

			ai = (dy - dx) * 2;
			bi = dy * 2;
			d = bi - dx;

			while (position.x != destx) // to nie powinno tu byc, to ma z kazdym update()
			{							// byc coraz blizej a nie naraz i wgl fuj, zrob jakis warunek?
				if (d >= 0)				// bool? zeby roznie ruszalo, ale tu czy w keyboard? hmm
				{
					position.x += velocity.x * speed * xi;
					position.y += velocity.y * speed * yi;
					d += ai;
				}
				else
				{
					position.x += velocity.x * speed * xi;
					d += bi;
				}
			}
		}

		else
		{
			ai = (dx - dy) * 2;
			bi = dx * 2;
			d = bi - dy;

			while (position.y != desty)
			{
				if (d >= 0)
				{
					position.x += velocity.x * speed * xi;
					position.y += velocity.y * speed * yi;
					d += ai;
				}
				else
				{
					d += bi;
					position.y += velocity.y * speed * yi;
				}
			}
		}		
	}



};
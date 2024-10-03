#include "dinosaur.h"

Dinosaur::Dinosaur()
{
	vertVelocity = 2;
}

Dinosaur::~Dinosaur()
{
}

bool Dinosaur::isDeath() const
{
	if (this->positionY <= 0 || this->positionY >= HEIGHT_MAX)
	{
		return true;
	}
	for (auto iter = gamemap.begin(); iter->x < WIDTH_MAX / 4; ++iter)
	{
		//ÉÏ·½¾ØÐÎ
		if (this->positionX + this->length >= iter->x && this->positionX <= iter->x + iter->width)
		{
			if (this->positionY <= iter->height || this->positionY >= (INTERVAL + iter->height))
			{
				return true;
			}
		}
	}
	return false;
}



void Dinosaur::Update()
{
	positionY += vertVelocity * DT;
	if(vertVelocity < 2)
	{
		vertVelocity += g * DT;
	}
}

void Dinosaur::Up()
{
	vertVelocity = (-2) * abs(vertVelocity + vertVelocity / 2);
}






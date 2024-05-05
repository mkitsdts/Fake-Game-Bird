#include "dinosaur.h"

Dinosaur::Dinosaur()
{
	vertVelocity = 2;
}

Dinosaur::~Dinosaur()
{
}



void Dinosaur::Update()
{
	positionY += vertVelocity * DT;
	vertVelocity = 2;
}

void Dinosaur::Up()
{
	vertVelocity = (-20) * abs(vertVelocity);
}






#include "Musuh.h"



Musuh::Musuh()
{
}


Musuh::~Musuh()
{
}

void Musuh::Move(int dx, int dy)
{
	this->x += dx;
	this->y += dy;
}

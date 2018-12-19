#include "Pemain.h"



Pemain::Pemain()
{
}


Pemain::~Pemain()
{
}

void Pemain::Right()
{
	this->x += 15;
}

void Pemain::Bottom()
{
	this->y += 15;
}

void Pemain::Left()
{
	this->x -= 15;
}

void Pemain::Up()
{
	this->y -= 15;
}

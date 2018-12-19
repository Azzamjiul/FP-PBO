#pragma once
#include "Mobil.h"
class Musuh :
	public Mobil
{
private:
	int x, y;
public:
	Musuh();
	~Musuh();
	void Move(int dx, int dy);
};


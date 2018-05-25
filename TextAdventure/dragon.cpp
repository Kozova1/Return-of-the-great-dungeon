#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>

int maxHP = 15;
int currentHP = 15;
void dragonKilled();
void playerDamaged(int damage);
void dragonDamaged(int damageTaken) 
{
	currentHP = currentHP - damageTaken;
	if (currentHP == 0)
		dragonKilled();
}

void attack()
{
	playerDamaged(2);
}
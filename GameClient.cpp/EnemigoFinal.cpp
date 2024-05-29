#include "EnemigoFinal.h"

EnemigoFinal::EnemigoFinal(int pHp, int pAttack, std::string pName, int pPositionX, int pPositionY, int pFireAttack, int pFrozenAttack) : Personaje(pHp, pAttack, pName, pPositionX, pPositionY)
{
	fireAttack = pFireAttack;
	frozenAttack = pFrozenAttack;
}

int EnemigoFinal::getFireAttack()
{
	return fireAttack;
}

int EnemigoFinal::getFrozenAttack()
{
	return frozenAttack;
}

void EnemigoFinal::setFireAttack(int pFireAttack)
{
	fireAttack = pFireAttack;
}

void EnemigoFinal::setFrozenAttack(int pFrozenAttack)
{
	frozenAttack = pFrozenAttack;
}
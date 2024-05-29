#include "Personaje.h"
#include <algorithm>
#include <cctype>

Personaje::Personaje()
{
    hp = 0;
    attack = 0;
    name = "Name";
    positionX = 0;
    positionY = 0;
}

Personaje::Personaje(int pHp, int pAttack, std::string pName, int pPositionX, int pPositionY)
{
    hp = pHp;
    attack = pAttack;
    name = pName;
    positionX = pPositionX;
    positionY = pPositionY;
}

int Personaje::getHp()
{
    return hp;
}

int Personaje::getAttack()
{
    return attack;
}

std::string Personaje::getName()
{
    return name;
}

int Personaje::getPositionX()
{
    return positionX;
}

int Personaje::getPositionY()
{
    return positionY;
}

void Personaje::setHp(int pHp)
{
    hp = pHp;
}

void Personaje::setAttack(int pAttack)
{
    attack = pAttack;
}

void Personaje::setName(std::string pName)
{
    name = pName;
}

void Personaje::setPositionX(int pPositionX)
{
    positionX = pPositionX;
}

void Personaje::setPositionY(int pPositionY)
{
    positionY = pPositionY;
}

void Personaje::getStats()
{
    std::cout << "Name: " << name << "\nHP: " << hp << "\nAttack: " << attack << "\nPosition: (" << positionX << ", " << positionY << ")\n";
}

std::pair<int, int> Personaje::getPosition()
{
    return std::make_pair(positionX, positionY);
}

void Personaje::move(int width, int height)
{
    if (_kbhit())
    {
        kbInput = tolower(_getch());
        switch (kbInput)
        {
        case 'a':
            if (positionY > 0)
                positionY--;
            break;
        case 'd':
            if (positionY < height - 1)
                positionY++;
            break;
        case 'w':
            if (positionX > 0)
                positionX--;
            break;
        case 's':
            if (positionX < width - 1)
                positionX++;
            break;
        default:
            break;
        }
    }
}

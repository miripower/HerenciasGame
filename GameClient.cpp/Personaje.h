#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <utility>

class Personaje
{
private:
    int hp;
    int attack;
    std::string name;
    int positionX;
    int positionY;

public:
    char kbInput = 0;

    // Constructor:
    Personaje();
    Personaje(int pHp, int pAttack, std::string pName, int pPositionX, int pPositionY);

    // Getters:
    int getHp();
    int getAttack();
    std::string getName();
    int getPositionX();
    int getPositionY();

    // Setters:
    void setHp(int pHp);
    void setAttack(int pAttack);
    void setName(std::string pName);
    void setPositionX(int pPositionX);
    void setPositionY(int pPositionY);

    // Métodos:
    void getStats();
    std::pair<int, int> getPosition();
    void move(int width, int height);
};

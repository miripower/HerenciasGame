#include <iostream>
#include "Personaje.h"
#include "EnemigoFinal.h"
#include "Juego.h"

#define BLACK   "\x1B[30m"
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1B[37m"
#define ORANGE  "\x1B[38;2;255;128;0m"
#define ROSE    "\x1B[38;2;255;151;203m"
#define LBLUE   "\x1B[38;2;53;149;240m"
#define LGREEN  "\x1B[38;2;17;245;120m"
#define GRAY    "\x1B[38;2;176;174;174m"
#define RESET   "\x1b[0m"

int main()
{
    srand(time(NULL));
	Juego::inicioJuego();
	char mapa[WIDTH][HEIGHT];
	Juego::iniciarMapa(mapa);

	Personaje Player = Personaje(300, 20, "Mario", 0, 7);

	Personaje Enemigo[4] = {
		Personaje(50, 10, "Koopa Troopa", Juego::randPosX(), Juego::randPosY()),
		Personaje(50, 10, "Goomba", Juego::randPosX(), Juego::randPosY()),
		Personaje(50, 10, "Lakitu", Juego::randPosX(), Juego::randPosY()),
		Personaje(50, 10, "Piranha Plant", Juego::randPosX(), Juego::randPosY())
	};

	EnemigoFinal FinalEnemy = EnemigoFinal(150, 30, "Bowser", WIDTH - 1, Juego::randPosY(), 50, 40);

	while (Player.getHp() > 0 && FinalEnemy.getHp() > 0)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		Player.move(WIDTH, HEIGHT);
		Juego::iniciarMapa(mapa);
		Juego::colocarPersonaje(mapa, Player, '0');
		Juego::colocarPersonaje(mapa, FinalEnemy, '-');

		for (int i = 0; i < 4; i++)
		{
			Juego::colocarPersonaje(mapa, Enemigo[i], '-');
		}

		Juego::mostrarMapa(mapa);

		Sleep(1);
		std::pair<int, int> playerPos = Player.getPosition();
		for (int i = 0; i < 4; i++)
		{
			if (Enemigo[i].getHp() <= 0)
			{
				std::cout << YELLOW << Enemigo[i].getName() << RESET << " ya ha sido derrotado!" << std::endl;
			}
			else if (playerPos == Enemigo[i].getPosition())
			{	
				system("cls");
				std::cout << "Te has encontrado con " << YELLOW << Enemigo[i].getName() << RESET << "! Preparate para la batalla" << std::endl;
				Sleep(1500);
				while (Enemigo[i].getHp() > 0 && Player.getHp() > 0)
				{
					if (Player.getHp() > 0)
					{
						int randPlayerDamage = rand() % 10;
						Player.setAttack(Player.getAttack() + randPlayerDamage);
						Enemigo[i].setHp(Enemigo[i].getHp() - Player.getAttack());
						std::cout << BLUE << Player.getName() << RESET << " ataca a " << YELLOW << Enemigo[i].getName() << RESET << " inflingiendo " << Player.getAttack() << " puntos de dano al enemigo y le quedan " << Enemigo[i].getHp() << " puntos de vida.\n" << std::endl;
						Sleep(2000);
					}

					if (Enemigo[i].getHp() > 0)
					{
						Player.setHp(Player.getHp() - Enemigo[i].getAttack());
						std::cout << YELLOW << Enemigo[i].getName() << RESET << " ataca a " << BLUE << Player.getName() << RESET << " inflingiendo " << Enemigo[i].getAttack() << " puntos de dano al jugador y le quedan " << Player.getHp() << " puntos de vida.\n" << std::endl;
						Sleep(2000);
					}
				}

				if (Player.getHp() > Enemigo[i].getHp()) 
				{
					std::cout  << YELLOW << Enemigo[i].getName() << GREEN << " ha sido derrotado!" << RESET << std::endl;
					Sleep(1500);
				}
				else if (Player.getHp() < Enemigo[i].getHp())
				{
					std::cout << RED << "HAS SIDO DERROTADO" << RESET << std::endl;
					Sleep(1500);
				}
				system("cls");
			}
		}

		if (Player.getPosition() == FinalEnemy.getPosition())
		{	
			system("cls");
			std::cout << "Has encontrado la salida! Pero... hay un porblema... La salida esta tapada por " << GREEN << FinalEnemy.getName() << RESET << ". Derrotalo para escapar!" << std::endl;
			Sleep(1500);
			while (FinalEnemy.getHp() > 0 && Player.getHp() > 0)
			{
				int randSuperAttack = rand() % 10;
				if (Player.getHp() > 0)
				{
					int randPlayerDamage = rand() % 10;
					Player.setAttack(Player.getAttack() + randPlayerDamage);
					FinalEnemy.setHp(FinalEnemy.getHp() - Player.getAttack());
					std::cout << BLUE << Player.getName() << RESET << " ataca a " << GREEN << FinalEnemy.getName() << RESET << " inflingiendo " << Player.getAttack() << " puntos de dano al enemigo y le quedan " << FinalEnemy.getHp() << " puntos de vida.\n" << std::endl;
					Sleep(2000);
				}
				if (FinalEnemy.getHp() > 0)
				{
					if (randSuperAttack == 1)
					{
						Player.setHp(Player.getHp() - FinalEnemy.getFireAttack());
						std::cout << GREEN << FinalEnemy.getName() << RESET << " ataca a " << BLUE << Player.getName() << RESET << " con su ataque de fuego inflingiendo " << FinalEnemy.getFireAttack() << " puntos de dano al jugador y le quedan " << Player.getHp() << " puntos de vida.\n" << std::endl;
						Sleep(2000);
					}
					else if (randSuperAttack == 2)
					{
						Player.setHp(Player.getHp() - FinalEnemy.getFrozenAttack());
						std::cout << GREEN << FinalEnemy.getName() << RESET << " ataca a " << BLUE << Player.getName() << RESET << " con su ataque de hielo inflingiendo " << FinalEnemy.getFrozenAttack() << " puntos de dano al jugador y le quedan " << Player.getHp() << " puntos de vida.\n" << std::endl;
						Sleep(2000);
					}
					else
					{
						Player.setHp(Player.getHp() - FinalEnemy.getAttack());
						std::cout << GREEN << FinalEnemy.getName() << RESET << " ataca a " << BLUE << Player.getName() << RESET << " inflingiendo " << FinalEnemy.getAttack() << " puntos de dano al jugador y le quedan " << Player.getHp() << " puntos de vida.\n" << std::endl;
						Sleep(2000);
					}
				}
			}
			if (Player.getHp() > FinalEnemy.getHp())
			{
				std::cout << GREEN << FinalEnemy.getName() << RESET << " ha sido derrotado!" << std::endl;
				Sleep(1500);
			}
			else if (Player.getHp() < FinalEnemy.getHp())
			{
				std::cout << RED << "HAS SIDO DERROTADO" << RESET << std::endl;
				Sleep(1500);
			}
			system("cls");
		}
	}

	if (Player.getHp() > 0)
	{
		std::cout << " __     ______  _    _  __          _______ _   _ " << std::endl;
		std::cout << " \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | |" << std::endl;
		std::cout << "  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| |" << std::endl;
		std::cout << "   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` |" << std::endl;
		std::cout << "    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |" << std::endl;
		std::cout << "    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_|" << std::endl;
	}
	else
	{
		std::cout << " __     ______  _    _   _      ____   _____ ______ " << std::endl;
		std::cout << " \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|" << std::endl;
		std::cout << "  \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__   " << std::endl;
		std::cout << "   \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|  " << std::endl;
		std::cout << "    | | | |__| | |__| | | |___| |__| |____) | |____ " << std::endl;
		std::cout << "    |_|  \\____/ \\____/  |______\\____/|_____/|______|" << std::endl;
	}

	return 0;
}
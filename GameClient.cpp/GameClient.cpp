#include <iostream>
#include "Personaje.h"
#include "EnemigoFinal.h"

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

const int WIDTH = 10;
const int HEIGHT = 20;

void iniciarMapa(char mapa[WIDTH][HEIGHT]) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			mapa[i][j] = '-';
		}
	}
}

void mostrarMapa(char mapa[WIDTH][HEIGHT]) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			std::cout << mapa[i][j];
		}
		std::cout << std::endl;
	}
}

int randPosX() {
	int randX = rand() % WIDTH;
	return randX;
}

int randPosY() {
	int randY = rand() % HEIGHT;
	return randY;
}

void colocarPersonaje(char mapa[WIDTH][HEIGHT], Personaje& personaje, char icono) {
	int posX = personaje.getPositionX();
	int posY = personaje.getPositionY();
	mapa[posX][posY] = icono;
}

void inicioJuego() {
	std::cout << "  _    _ ______ _____  ______ _   _  _____ _____           _____ " << std::endl;
	std::cout << " | |  | |  ____|  __ \\|  ____| \\ | |/ ____|_   _|   /\\    / ____|" << std::endl;
	std::cout << " | |__| | |__  | |__) | |__  |  \\| | |      | |    /  \\  | (___  " << std::endl;
	std::cout << " |  __  |  __| |  _  /|  __| | . ` | |      | |   / /\\ \\  \\___ \\ " << std::endl;
	std::cout << " | |  | | |____| | \\ \\| |____| |\\  | |____ _| |_ / ____ \\ ____) |" << std::endl;
	std::cout << " |_|__|_|______|_|__\\_\\______|_| \\_|\\_____|_____/_/    \\_\\_____/ " << std::endl;
	std::cout << "  / ____|   /\\   |  \\/  |  ____|                                 " << std::endl;
	std::cout << " | |  __   /  \\  | \\  / | |__                                    " << std::endl;
	std::cout << " | | |_ | / /\\ \\ | |\\/| |  __|                                   " << std::endl;
	std::cout << " | |__| |/ ____ \\| |  | | |____                                  " << std::endl;
	std::cout << "  \\_____/_/    \\_\\_|_ |_|______|_  __ _          _               " << std::endl;
	std::cout << " | |           |  __ \\    | | |  \\/  (_)        | |              " << std::endl;
	std::cout << " | |__  _   _  | |__) |__ | | | \\  / |_ _ __ ___| |_             " << std::endl;
	std::cout << " | '_ \\| | | | |  ___/ _ \\| | | |\\/| | | '__/ _ \\ __|            " << std::endl;
	std::cout << " | |_) | |_| | | |  | (_) | | | |  | | | | |  __/ |_             " << std::endl;
	std::cout << " |_.__/ \\__, | |_|   \\___/|_| |_|  |_|_|_|  \\___|\\__|            " << std::endl;
	std::cout << "         __/ |                                                   " << std::endl;
	std::cout << "        |___/                                                    " << std::endl;
	system("pause");
	system("cls");
}

int main()
{
    srand(time(NULL));
	inicioJuego();
	char mapa[WIDTH][HEIGHT];
	iniciarMapa(mapa);

	Personaje Player = Personaje(300, 20, "Mario", 0, 7);

	Personaje Enemigo[4] = {
		Personaje(50, 10, "Koopa Troopa", randPosX(), randPosY()),
		Personaje(50, 10, "Goomba", randPosX(), randPosY()),
		Personaje(50, 10, "Lakitu", randPosX(), randPosY()),
		Personaje(50, 10, "Piranha Plant", randPosX(), randPosY())
	};

	EnemigoFinal FinalEnemy = EnemigoFinal(150, 30, "Bowser", WIDTH - 1, randPosY(), 50, 40);

	while (Player.getHp() > 0 && FinalEnemy.getHp() > 0)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		Player.move(WIDTH, HEIGHT);
		iniciarMapa(mapa);
		colocarPersonaje(mapa, Player, '0');
		colocarPersonaje(mapa, FinalEnemy, 'S');

		for (int i = 0; i < 4; i++)
		{
			colocarPersonaje(mapa, Enemigo[i], 'E');
		}

		mostrarMapa(mapa);

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
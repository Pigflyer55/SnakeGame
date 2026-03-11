#include "SnakeGame.h"

SnakeGame::SnakeGame(int width=20, int height=20) : width(width), height(height)
{
	gameInit();
}

void SnakeGame::gameInit() {
	this->gameOver = false;
	this->snakeDirection = STOP;
	this->x = this->width / 2;
	this->y = this->height / 2;
	this->fruitCoordX = rand() % this->width;
	this->fruitCoordY = rand() % this->height;
	this->snakeTailLength = 0;
}

void SnakeGame::gameRender() {
	system("cls");
	for (int i = 0; i < this->width + 2; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;
	for (int i = 0; i < this->height; i++) {
		std::cout << "|";
		for (int j = 0; j < this->width; j++) {
			
			if (i == this->y && j == this->x) {
				std::cout << "O";
			} 
			else if (i == this->fruitCoordY && j == this->fruitCoordX) {
				std::cout << "F";
			}
			else {
				bool printTail = false;
				for (int s = 0; s < this->snakeTailLength; s++) {
					if (this->snakeTailX[s] == j && this->snakeTailY[s] == i) {
						printTail = true;
						std::cout << "@";
					}
				}
				if (!printTail) {
					std::cout << " ";
				}
			}

		}
		std::cout << "|" << std::endl;
	}
	for (int i = 0; i < this->width + 2; i++) {
		std::cout << "-";
	}
	std::cout << std::endl;

	std::cout << "Score: " << this->playerScore << std::endl;
}

void SnakeGame::updateGame() {
	
	int prevX = this->snakeTailX[0];
	int prevY = this->snakeTailY[0];
	this->snakeTailX[0] = x;
	this->snakeTailY[0] = y;
	int prev2X, prev2Y;
	for (int i = 1; i < this->snakeTailLength; i++) {
		int prev2X = this->snakeTailX[i];
		int prev2Y = this->snakeTailY[i];
		this->snakeTailX[i] = prevX;
		this->snakeTailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (this->snakeDirection) {
	case(UP):
		this->y--;
		break;
	case(DOWN):
		this->y++;
		break;
	case(LEFT):
		this->x--;
		break;
	case(RIGHT):
		this->x++;
		break;
	}

	if (this->x >= this->width || this->x < 0 || this->y >= this->height || this->y < 0) {
		this->gameOver = true;
	}

	for (int i = 0; i < this->snakeTailLength; i++) {
		if (this->x == this->snakeTailX[i] && this->y == this->snakeTailY[i]) {
			this->gameOver = true;
		}
	}

	if (this->x == this->fruitCoordX && this->y == this->fruitCoordY) {
		this->playerScore += 1;
		this->fruitCoordX = rand() % this->width;
		this->fruitCoordY = rand() % this->height;
		this->snakeTailLength += 1;
	}
}

void SnakeGame::userInput()
{
	if (_kbhit()) {
		std::cout << "Key Pressed" << std::endl;
		switch (_getch()) {
		case 'a':
			this->snakeDirection = LEFT;
			break;
		case 'd':
			this->snakeDirection = RIGHT;
			break;
		case 'w':
			this->snakeDirection = UP;
			break;
		case 's':
			this->snakeDirection = DOWN;
			break;
		case 'x':
			this->gameOver = true;
		}
	}
}

int SnakeGame::setDifficulty()
{
	int dfc, choice;
	std::cout << "1,2,3";
	std::cin >> choice;
	
	switch (choice) {
	case '1':
		dfc = 100;
		break;
	case '2':
		dfc = 200;
		break;
	case '3':
		dfc = 300;
		break;
	default:
		dfc = 100;
	}
	return dfc;
}
#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

class SnakeGame
{
public:
	SnakeGame(int width, int height);
	~SnakeGame();
	enum Direction { STOP = 0, UP, DOWN, LEFT, RIGHT };
	int x, y;
	int fruitCoordX, fruitCoordY;
	int playerScore = 0;
	int const width, height;
	int snakeTailX[100], snakeTailY[100];
	int snakeTailLength;
	Direction snakeDirection;
	bool gameOver;
	void gameInit();
	void gameRender();
	void updateGame();
	void userInput();
	int setDifficulty();


private:

};


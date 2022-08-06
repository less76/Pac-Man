#include "pch.h"
#include "Pachead.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

Pachead::~Pachead() {
	for (int i = 0; i < board_size; ++i)
		delete[] gameboard[i];

	delete[] gameboard;
}

void Pachead::Clear() {
	for (int i = 0; i < board_size; i++)
		for (int j = 1; j < board_size + 1; j++)
			gameboard[i][j] = ' ';

	for (int i = 0; i < 6; i++)
		gameboard[board_size - 2][2 + i] = '_';
	
	for (int i = 0; i < 2; i++)
		gameboard[board_size - (2 + i)][5] = '|';
	

}

void Pachead::Draw() {

	for (int i = 0; i < 1; i++) {
		cout << " ";
	}

	for (int i = 0; i < (board_size << 2) - 17; i++) {
		cout << "_";
	}

	cout << endl;

	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size + 1; j++) {
			cout << " " << gameboard[i][j] << " ";
		}

		cout << " | "<< endl;
	}

	cout << " |";

	for (int i = 0; i < (board_size << 2) - 18; i++) {
		cout << "_";
	}

	cout << "| ";

}

Pachead::Pachead() {
	x = board_size >> 1;
	y = board_size >> 1;

	gameboard = new char*[board_size];

	for (int i = 0; i < board_size; i++)
		gameboard[i] = new char[board_size+1];

	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size + 1; j++) {
			if (j == 0) {
				gameboard[i][j] = '|';
			}

			else {
				gameboard[i][j] = ' ';
			}
			
		}
	}
	
	

}

void Pachead::gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

void Pachead::ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}



void Pachead::Direction() {

	Clear();

	if (_kbhit())
	{
		switch (_getch())
		{
		case 75:
			dir = LEFT;
			break;
		case 77:
			dir = RIGHT;
			break;
		case 72:
			dir = UP;
			break;
		case 80:
			dir = DOWN;
			break;

		}
	}

	switch (dir) {
		
	case LEFT:
		if (x > 1) {
			x--;
		}
		
		break;

	case RIGHT:
		if (x <= board_size - 1) {
			x++;
		}

		break;

	case UP:
		if (y > 0) {
			y--;
		}
		break;

	case DOWN:
		if (y < board_size -1) {
			y++;
		}
		break;

	default:
		break;
	}

}

void Pachead::Logic() {
	gameboard[y][x] = 'P';

	gotoxy(0, 0);
}
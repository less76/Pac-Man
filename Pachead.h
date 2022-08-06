#pragma once
#define board_size 20
class Pachead
{
private:
	char **gameboard;
	int x, y;

	enum eDirection {
		STOP = 0,
		LEFT, RIGHT,
		UP, DOWN
	};
	eDirection dir;

public:
	Pachead();
	~Pachead();
	void Draw();
	void gotoxy(int, int);
	void ShowConsoleCursor(bool);
	void Direction();
	void Logic();
	void Clear();
};


#include "head.h"

void PlayerInitialize(int posY, int posX)
{
	player.Y = posY;
	player.X = posX;

	dest.Y = SIZE - 2;
	dest.X = SIZE - 2;
}

int dir = UP; // �ٶ󺸰� �ִ� ���� �ʱ�ȭ
void Update()
{
	// enum { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 }
	// ���� �ٶ󺸰� �ִ� ������ �������� ��ǥ ��ȭ�� ��Ÿ����.
	int frontY[4] = { -1, 0, 1, 0 };
	int frontX[4] = { 0, -1, 0, 1 };
	int rightY[4] = { 0, -1, 0, 1 };
	int rightX[4] = { 1, 0, -1, 0 };


	// 1. ���� �ٶ󺸴� ������ �������� ���������� �� �� �ִ��� Ȯ��
	if (board[player.Y + rightY[dir]][player.X + rightX[dir]] == EMPTY)
	{
		// ������ �������� 90�� ȸ��
		dir = (dir - 1 + 4) % 4;

		// ������ �� �� ����
		player.Y = player.Y + frontY[dir];
		player.X = player.X + frontX[dir];
	}
	// 2. ���� �ٶ󺸴� ������ �������� ������ �� �ִ��� Ȯ��
	else if (board[player.Y + frontY[dir]][player.X + frontX[dir]] == EMPTY)
	{
		// ������ �� �� ����
		player.Y = player.Y + frontY[dir];
		player.X = player.X + frontX[dir];
	}
	else
	{
		// ���� �������� 90�� ȸ��
		dir = (dir + 1 + 4) % 4;
	}
}

void Finish()
{
	SetCursorPosition(0, 0);
	Render();
	SetConsoleTextColor(WHITE);
	PrintClear();
	Sleep(2000);
}
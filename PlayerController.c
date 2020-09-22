#include "head.h"

void PlayerInitialize(int posY, int posX)
{
	player.Y = posY;
	player.X = posX;

	dest.Y = SIZE - 2;
	dest.X = SIZE - 2;
}

int dir = UP; // 바라보고 있는 방향 초기화
void Update()
{
	// enum { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 }
	// 현재 바라보고 있는 방향을 기준으로 좌표 변화를 나타낸다.
	int frontY[4] = { -1, 0, 1, 0 };
	int frontX[4] = { 0, -1, 0, 1 };
	int rightY[4] = { 0, -1, 0, 1 };
	int rightX[4] = { 1, 0, -1, 0 };


	// 1. 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인
	if (board[player.Y + rightY[dir]][player.X + rightX[dir]] == EMPTY)
	{
		// 오른쪽 방향으로 90도 회전
		dir = (dir - 1 + 4) % 4;

		// 앞으로 한 보 전진
		player.Y = player.Y + frontY[dir];
		player.X = player.X + frontX[dir];
	}
	// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인
	else if (board[player.Y + frontY[dir]][player.X + frontX[dir]] == EMPTY)
	{
		// 앞으로 한 보 전진
		player.Y = player.Y + frontY[dir];
		player.X = player.X + frontX[dir];
	}
	else
	{
		// 왼쪽 방향으로 90도 회전
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
#include "head.h"

void GenerateByBinaryTree()
{
	// 일단 길을 다 막아버리는 작업
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				board[y][x] = WALL;
			else
				board[y][x] = EMPTY;
		}
	}

	// 랜덤으로 오른쪽 또는 아래로 길을 뚫는 작업
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (y == SIZE - 2 && x == SIZE - 2)
				continue;

			if (y == SIZE - 2)
			{
				board[y][x + 1] = EMPTY;
				continue;
			}

			if (x == SIZE - 2)
			{
				board[y + 1][x] = EMPTY;
				continue;
			}

			if (rand() % 2 == 0)
				board[y][x + 1] = EMPTY;
			else
				board[y + 1][x] = EMPTY;

		}
	}
}

void GenerateBySideWinder()
{
	// 일단 길을 다 막아버리는 작업
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				board[y][x] = WALL;
			else
				board[y][x] = EMPTY;
		}
	}

	// 랜덤으로 오른쪽 또는 아래로 길을 뚫는 작업
	for (int y = 0; y < SIZE; y++)
	{
		int count = 1;
		for (int x = 0; x < SIZE; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;

			if (y == SIZE - 2 && x == SIZE - 2)
				continue;

			if (y == SIZE - 2)
			{
				board[y][x + 1] = EMPTY;
				continue;
			}

			if (x == SIZE - 2)
			{
				board[y + 1][x] = EMPTY;
				continue;
			}

			if (rand() % 2 == 0)
			{
				board[y][x + 1] = EMPTY;
				count++;
			}
			else
			{
				int randomIndex = rand() % count;
				board[y + 1][x - randomIndex * 2] = EMPTY;
				count = 1;
			}
		}
	}
}

void MapInitialize()
{
	srand((unsigned)time(NULL));
	// GenerateByBinaryTree();
	GenerateBySideWinder();
}

int GetTileColor(int y, int x)
{
	switch (board[y][x])
	{
	case EMPTY:
		return BLACK;
	case WALL:
		return RED;
	default:
		return GREEN;
	}
}

void Render() // 맵 렌더링하기
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			// 플레이어 좌표를 갖고 와서, 그 좌표랑 현재 y, x가 일치하면 플레이어 전용 색상으로 표시.
			if (y == player.Y && x == player.X)
				SetConsoleTextColor(GREEN);
			else if (y == dest.Y && x == dest.X)
				SetConsoleTextColor(YELLOW);
			else
				SetConsoleTextColor(GetTileColor(y, x));

			printf("●");
		}
		printf("\n");
	}
}
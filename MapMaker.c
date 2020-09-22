#include "head.h"

void GenerateByBinaryTree()
{
	// �ϴ� ���� �� ���ƹ����� �۾�
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

	// �������� ������ �Ǵ� �Ʒ��� ���� �մ� �۾�
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
	// �ϴ� ���� �� ���ƹ����� �۾�
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

	// �������� ������ �Ǵ� �Ʒ��� ���� �մ� �۾�
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

void Render() // �� �������ϱ�
{
	for (int y = 0; y < SIZE; y++)
	{
		for (int x = 0; x < SIZE; x++)
		{
			// �÷��̾� ��ǥ�� ���� �ͼ�, �� ��ǥ�� ���� y, x�� ��ġ�ϸ� �÷��̾� ���� �������� ǥ��.
			if (y == player.Y && x == player.X)
				SetConsoleTextColor(GREEN);
			else if (y == dest.Y && x == dest.X)
				SetConsoleTextColor(YELLOW);
			else
				SetConsoleTextColor(GetTileColor(y, x));

			printf("��");
		}
		printf("\n");
	}
}
#pragma once

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25  // Ȧ��
int board[SIZE][SIZE]; // ��(�̷�)�� ��Ÿ���� �迭

enum { EMPTY = 0, WALL = 1 }; // board �迭�� ������ ���� enum��
enum { BLACK = 0, BLUE = 1, GREEN = 2, AQUA = 3, RED = 4, PURPLE = 5, YELLOW = 6, WHITE = 7, GRAY = 8 }; // �ܼ� �ؽ�Ʈ ���� enum��
enum { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 }; // �÷��̾��� ������ ��Ÿ���� enum��

typedef struct _Player // �÷��̾� ��ǥ�� ��Ÿ���� ����ü
{
	int Y;
	int X;
} Player; Player player;
typedef struct _Dest // ������ ��ǥ�� ��Ÿ���� ����ü
{
	int Y;
	int X;
} Dest; Dest dest;

// ConsoleController.c
void SetCursorPosition(int x, int y); // x,y ��ǥ �̵���Ű�� �Լ�
void ConsoleSize(); // �ܼ�â ũ�� ����
void RemoveScrollbar(); // �ܼ�â ��ũ�ѹ� ����
void RemoveCursor(); // �ܼ�â Ŀ�� ����
void SetConsole(); // �ܼ�â ���� �Լ� ����
void SetConsoleTextColor(int color); // �ܼ� �ؽ�Ʈ ���� ����
void PrintClear(); // �� ã�� �Ϸ� �� �ֿܼ� �ƽ�Ű ��Ʈ�� "CLEAR!" ����ϱ�


// MapMaker.c
void GenerateByBinaryTree(); // BinaryTree �̷� ���� �˰���
void GenerateBySideWinder(); // SideWinder �̷� ���� �˰���
void MapInitialize(); // �� �ʱ�ȭ
int GetTileColor(int y, int x); // Ư�� ��ǥ Ÿ�� ����(enum��) ���ϱ�
void Render(); // �� ������


// PlayerController.c
void PlayerInitialize(int posY, int posX); // �÷��̾� �� ������ ��ġ �ʱ�ȭ
void Update(); // �� �����Ӹ��� �÷��̾��� ��ġ ����
void Finish(); // �� ã�⸦ �Ϸ����� �� ȣ��Ǵ� �Լ�
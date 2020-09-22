#pragma once

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25  // 홀수
int board[SIZE][SIZE]; // 맵(미로)을 나타내는 배열

enum { EMPTY = 0, WALL = 1 }; // board 배열의 값으로 쓰일 enum값
enum { BLACK = 0, BLUE = 1, GREEN = 2, AQUA = 3, RED = 4, PURPLE = 5, YELLOW = 6, WHITE = 7, GRAY = 8 }; // 콘솔 텍스트 색상 enum값
enum { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 }; // 플레이어의 방향을 나타내는 enum값

typedef struct _Player // 플레이어 좌표를 나타내는 구조체
{
	int Y;
	int X;
} Player; Player player;
typedef struct _Dest // 목적지 좌표를 나타내는 구조체
{
	int Y;
	int X;
} Dest; Dest dest;

// ConsoleController.c
void SetCursorPosition(int x, int y); // x,y 좌표 이동시키는 함수
void ConsoleSize(); // 콘솔창 크기 조절
void RemoveScrollbar(); // 콘솔창 스크롤바 삭제
void RemoveCursor(); // 콘솔창 커서 제거
void SetConsole(); // 콘솔창 세팅 함수 모음
void SetConsoleTextColor(int color); // 콘솔 텍스트 색상 변경
void PrintClear(); // 길 찾기 완료 시 콘솔에 아스키 아트로 "CLEAR!" 출력하기


// MapMaker.c
void GenerateByBinaryTree(); // BinaryTree 미로 생성 알고리즘
void GenerateBySideWinder(); // SideWinder 미로 생성 알고리즘
void MapInitialize(); // 맵 초기화
int GetTileColor(int y, int x); // 특정 좌표 타일 색상(enum값) 구하기
void Render(); // 맵 렌더링


// PlayerController.c
void PlayerInitialize(int posY, int posX); // 플레이어 및 목적지 위치 초기화
void Update(); // 매 프레임마다 플레이어의 위치 갱신
void Finish(); // 길 찾기를 완료했을 때 호출되는 함수
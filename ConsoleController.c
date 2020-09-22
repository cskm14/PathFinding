#include "head.h"

void SetCursorPosition(int y, int x)
{
    COORD pos = { y, x };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ConsoleSize()
{
    system("mode con cols=80 lines=35"); // 가로 80, 세로 35으로 설정
}

void RemoveCursor()
{
    CONSOLE_CURSOR_INFO curinfo = { 0, };
    curinfo.dwSize = 1;
    curinfo.bVisible = 0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
}

void RemoveScrollbar()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size =
    {
        info.srWindow.Right - info.srWindow.Left + 1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
}

void SetConsoleTextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SetConsole()
{
    ConsoleSize();
    RemoveScrollbar();
    RemoveCursor();
    SetConsoleTextColor(GREEN);
}

void PrintClear()
{
    printf("\n");
    printf("   ####    ####    #######    ##    ######    ##   \n");
    printf("  ##  ##   ##      ##  ##    ####    ##  ##   ##     \n");
    printf("  ##       ##      ##       ##  ##   ##  ##   ##     \n");
    printf("  ##       ##      ####     ######   #####    ##     \n");
    printf("  ##       ##      ##       ##  ##   ####             \n");
    printf("  ##  ##   ##      ##  ##   ##  ##   ## ##            \n");
    printf("   ####    ######  #######  ##  ##  ###  ##   ##     \n");
}
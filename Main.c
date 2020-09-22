#include "head.h"

int main()
{
    while (1) 
    {
        // 초기 세팅
        SetConsole(); 
        MapInitialize();
        PlayerInitialize(1, 1);

        while (1)
        {
            if (player.Y != dest.Y || player.X != dest.X) // 목적지 도착하기 전까지 계속 실행
            {
                // 로직
                Update();

                // 렌더링
                SetCursorPosition(0, 0);
                Render();
            }
            else // 목적지에 도착했을 때
            {
                Finish();
                break;
            }
        }
    }
    return 0;
}
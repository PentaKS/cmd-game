// #include "mechanics.h"
#include "loading_screen.h"
#include <winuser.h>
// #include <cstdlib>
// #include <synchapi.h>
// #include <winuser.h>
// #include <thread>
// #include <playsoundapi.h>
// #include <synchapi.h>
// #include "bot2.h"
// #include <thread>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleTitle(TEXT("CMD GAME"));
    display_game_name();
    // std::thread menu_music(music_menu);
    // Sleep(200);
    system("CLS");
    while (true)
    {
        // ShellExecute(NULL, "open", "music.exe", NULL, NULL, SW_SHOWMINIMIZED);
        menu_start();
        // char key = 'a';
        // key = getch();
        if (key_pressed == true)
        {
            if (y[posy] == 14)
            {
                break;
            }
        }
        // Sleep(2000);
        mechanics();
        key_pressed = false;
    }
    // key_pressed = false;

    return 0;
}
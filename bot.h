#include "loading_screen.h"
#include <random>

int bot()
{
    hideccursor();
    SetConsoleOutputCP(CP_UTF8);
    std::random_device r;
    std::default_random_engine el(r());
    std::uniform_int_distribution<int> distribution(1, 7);
    // int mean = distribution(el);
    // std::cout << " randomly choosen int : " << mean << std::endl;

    object enemy;
    // enemy.initialize_coord_e();
    enemy.look = "o[..]o";
    gotoxy(60, 15);
    enemy.display();
    enemy.init_posx = 60;
    enemy.init_posy = 15;
    for (int i = 1; i < 190; i++)
    {
        int mean = distribution(el);
        // std::cout << " randomly choosen int : " << mean << std::endl;
        if (mean == (5))
        {
            enemy.cleardown();

            enemy.walk_up();
            // enemy.display();

            Sleep(2000);
        }
        else if (mean == (7))
        {
            enemy.clearup();

            enemy.walk_down();
            // enemy.display();
        }
        else if (mean == 2)
        {
            enemy.laser(120);
            Sleep(50);
            gotoxy(0, enemy.init_posy);
            enemy.clearlaser();
        }
    }
}
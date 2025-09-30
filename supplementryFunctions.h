#include <windows.h>
#include <iostream>

void gotoxy(int x, int y)
{
    COORD xy;
    xy.X = x;
    xy.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void looped_print(int times, std::string string)
{
    std::string output;
    for (int i = 1; i < times; i++)
    {
        output = output + string;
        std::cout << string;
        // Sleep(50);
    }
}

void looped_print_a(int times, std::string string)
{
    std::string output;
    for (int i = 1; i < times; i++)
    {
        output = output + string;
        std::cout << string;
        Sleep(10);
    }
}


void animation (int y)
{
    gotoxy(0, y);
    looped_print(60 , " ");
    gotoxy(0,y);
    looped_print(60, " ");
}

auto blue  = FOREGROUND_BLUE;
auto red = FOREGROUND_RED;
auto green = FOREGROUND_GREEN;
auto bright  = FOREGROUND_INTENSITY;
auto black = 0;
auto white = 7;
auto yellow = 6;
auto cyan = 3;
auto magenta = 5;

void set_text_color(WORD color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void hideccursor()
{
    // COORD coordinates;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    _CONSOLE_CURSOR_INFO ci;
    GetConsoleCursorInfo(h, &ci);
    ci.bVisible = FALSE;
    SetConsoleCursorInfo(h, &ci);
}




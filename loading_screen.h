#include "mechanics.h"

void display_game_name()
{
    // line 1
    gotoxy(31, 5);
    std::cout << "▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮  ▮▮▮▮            ▮▮▮▮  ▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮";
    gotoxy(29, 6);
    std::cout << "▮▮                  ▮▮  ▮▮        ▮▮  ▮▮  ▮▮               ▮▮";
    gotoxy(27, 7);
    std::cout << "▮▮                    ▮▮    ▮▮    ▮▮    ▮▮  ▮▮                 ▮▮";
    gotoxy(27, 8);
    std::cout << "▮▮                    ▮▮      ▮▮▮▮      ▮▮  ▮▮                   ▮▮";
    gotoxy(27, 9);
    std::cout << "▮▮                    ▮▮       ▮▮       ▮▮  ▮▮                   ▮▮";
    gotoxy(27, 10);
    std::cout << "▮▮                    ▮▮                ▮▮  ▮▮                   ▮▮";
    gotoxy(27, 11);
    std::cout << "▮▮                    ▮▮                ▮▮  ▮▮                   ▮▮";
    gotoxy(27, 12);
    std::cout << "▮▮                    ▮▮                ▮▮  ▮▮                 ▮▮";
    gotoxy(29, 13);
    std::cout << "▮▮                  ▮▮                ▮▮  ▮▮               ▮▮";
    gotoxy(31, 14);
    std::cout << "▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮  ▮▮                ▮▮  ▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮▮";
    gotoxy(53, 17);
    std::cout << "-----GAME-----";
    // gotoxy(51, 19);
    //          std::cout << "::              ::";
    // gotoxy(49, 20);
    //        std::cout << "::                  ::";
    // gotoxy(44, 21);
    // std::cout << "::  ::                    ::  ::";
    // gotoxy(43, 22);
    //     std::cout << ":  :  ::   ::        ::   ::  :  :";
    // gotoxy(44, 23);
    // std::cout << "::    ::                ::    ::";
    gotoxy(48, 19);
    std::cout << "---BY KUMUD SARASWAT---";
    gotoxy(15, 21);
    looped_print(90, "—");
    gotoxy(15, 22);
    std::cout << "";
    looped_print_a(90, "▮");
    std::cout << "";
}
// globals
int posy = 0;
int y[3] = {12, 13, 14};
bool key_pressed = false;

// menu loop
void menu_start()
{

    gotoxy(16, 6);
    std::cout << "Welcome To My Game, Please Select from the given options via your <W> and <S> keys.";
    gotoxy(42, 7);
    std::cout << "--press <space> to select an option--";
    std::string option;
    // std::string option1 = "  New Game  ";
    std::string option1 = "  Play Against a bot o[..]o  ";
    std::string option2 = "  Continue  ";
    std::string option3 = "  Exit  ";

    // std::string option1s = "< New Game >";
    std::string option1s = "< Play Against a bot o[..]o >";
    std::string option2s = "< Continue >";
    std::string option3s = "< Exit >";
    gotoxy(25, 9);
    std::cout << "Some features are not available yet.... and have < × > sign if front";
    gotoxy(48, 13);
    std::cout << "×";
        gotoxy(50, 12);
    // set_text_color(blue);
    std::cout << option1s;
    // set_text_color(white);
    gotoxy(50, 13);
    std::cout << option2;
    gotoxy(50, 14);
    std::cout << option3;
    while (key_pressed != true)
    {

        char input = 'a';
        input = getch();

        switch (input)
        {
        case 'w' | 'W':

            if (y[posy] == 14)
            {
                gotoxy(50, 13);
                set_text_color(red | bright);
                std::cout << option2s;
                set_text_color(white);
                gotoxy(50, 14);
                std::cout << option3;
                posy = 1;
            }
            else if (y[posy] == 13)
            {
                gotoxy(50, 12);
                // set_text_color(blue | bright);
                std::cout << option1s;
                // set_text_color(white);
                gotoxy(50, 13);
                std::cout << option2;
                posy = 0;
            }
            break;
        case 's' | 'S':
        {
            if (y[posy] == 12)
            {
                gotoxy(50, 13);
                set_text_color(red | bright);
                std::cout << option2s;
                set_text_color(white);
                gotoxy(50, 12);
                std::cout << option1;
                posy = 1;

                // std::cout << posy;
                // break;
            }
            // Sleep(2000);
            else if (y[posy] == 13)
            {
                gotoxy(50, 14);
                // set_text_color(red | blue | bright);
                std::cout << option3s;
                // set_text_color(white);
                gotoxy(50, 13);
                set_text_color(white);
                std::cout << option2;
                posy = 2;

                // std::cout << posy;
                // break;
            }
            break;
        }

        case ' ' :

            if (y[posy] == 12)
            {
                key_pressed = true;
                // mechanics();
                system("CLS");
                // mechanics();
                break;
                
            }
            if (y[posy] == 14)
            {
                key_pressed = true;
                system("CLS");
                break;
            }
            break;
        }
    }

} 
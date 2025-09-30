#include <conio.h>
// #include <cstdlib>
// #include <synchapi.h>
// #include <thread>
// #include <windows.h>
#include "classes.h"
#include <random>

// #include <c

char input = 'a';

void mechanics() {
  hideccursor();
  SetConsoleOutputCP(CP_UTF8);
  // player
  object player;
  player.look = "o(..)o";
  player.initialize_coord();
  // gotoxy(player.init_posx, player.init_posy-1);
  player.display();
  player.marklin();


  //   object enemy;
  //   enemy.look = "d(^..^)b";
  //   enemy.initialize_coord_e();
  //   enemy.display();

  int max_y = 25;
  int min_y = 12;

  int max_x = 114;
  int min_x = 6;

  bool laser_fired = false;

  hideccursor();
  SetConsoleOutputCP(CP_UTF8);
  // enemy
  Enemy enemy;
  enemy.look = "o[..]o";
  enemy.initialize_coord_e();
  // enemy.markline();
  enemy.display();
  enemy.markline();

  // object enemy;
  // enemy.look = "d(^..^)b";
  // enemy.initialize_coord_e();
  // enemy.display();

  //   int max_y_e = 25;
  //   int min_y_e = 5;

  //   int max_x_e = 114;
  //   int min_x_e = 6;
  stats();

  bool laser_fired_e = false;
  // logic loop
  while (true) {
    // int lenth = 6;
    input = getch();
    switch (input) {
    // vertical movement mechanism
    case 's':
      if (player.init_posy <= max_y) {
        player.clearup();
        player.walk_down();
        player.marklin();
        player.clearmark();
      }
      break;
      // system("CLS");
    case 'w':
      if (player.init_posy >= min_y) {
        player.cleardown();
        player.walk_up();
        player.marklin();
      }
      break;
      // system("CLS");

      // horizontal movement mechanism
    case 'd':
      if (player.init_posx <= max_x) {
        player.clearright();
        player.walk_right();
        // system("CLS");
      }
      break;
    case 'a': {
      if (player.init_posx > min_x) {
        player.clearleft();
        player.walk_left();
        // system("CLS");
      }
      break;
    }
      // laser attack mehcanism
    case 'e': {
      if (sheild_active == true) {
        player.laser(80);
        laser_fired = true;
      } else if (sheild_active == false) {
        player.laser(120);
        laser_fired = true;
        // Sleep(50);
      }
      Sleep(50);
      if (laser_fired == true) {
        gotoxy(0, player.init_posy);
        player.clearlaser();
        player.display();
        // laser_fired = false;
      }
      if (player.init_posy == enemy.init_posy) {
        updateHealthe(enemy);
      }
      break;
    }
    case 'q':
      // │ LONG
      player.sheild();
      break;
    default:
      break;
    }
    // if (input == ' ') {
    //   system("CLS");
    //   break;
    // }
    // if (input == 27) {
    //   system("CLS");
    //   break;
    // }

    // system("CLS");

    std::random_device rd;

    // char input = 'a';

    // void bot() {

    // logic loop
    // while (true) {

    // std::default_random_engine el(rd());
    std::uniform_int_distribution<int> ud(1, 5);
    int mean = ud(rd);

    // int lenth = 6;
    // input = getch();
    switch (mean) {
    // vertical movement mechanism
    case 2:
      if (enemy.init_posy <= max_y) {
        enemy.clearup_e();
        enemy.walk_down_e();
        enemy.markline();
        enemy.clearmarke();
      }
      break;
      // system("CLS");
    case 4:
      if (enemy.init_posy >= min_y) {
        enemy.cleardown_e();
        enemy.walk_up_e();
        enemy.markline();
      }
      break;
      // system("CLS");

      // horizontal movement mechanism
    // case :
    //   if (enemy.init_posx <= max_x) {
    //     enemy.clearright_e();
    //     enemy.walk_right_e();
    //     // system("CLS");
    //   }
    //   break;
    // case 'a': {
    //   if (enemy.init_posx > min_x) {
    //     enemy.clearleft_e();
    //     enemy.walk_left_e();
    //     // system("CLS");
    //   }
    //   break;
    // }
    // laser attack mehcanism
    case 5: {
      if (sheild_active == true) {
        enemy.laser_e(80);
        laser_fired_e = true;
      } else if (sheild_active == false) {
        enemy.laser_e(120);
        laser_fired_e = true;
        // Sleep(50);
      }
      Sleep(50);
      if (laser_fired_e == true) {
        gotoxy(0, enemy.init_posy);
        enemy.clearlaser_e();
        enemy.display();
        // laser_fired = false;
      }
      if (enemy.init_posy == player.init_posy) {
        updateHealth(player);
      }
      break;
    }
    case 6:
      // │ LONG
      enemy.sheild_e();
      break;
    default:
      break;
    }
    if (player.health == 0) {
      system("CLS");
      gotoxy(60 - 9, 15);
      std::cout << "You Lost <Defeat>";
      Sleep(1000);
      gotoxy(30, 20);
      std::cout << "[";
      looped_print_a(60, "|");
      std::cout << "]";
      Sleep(3000);
      system("CLS");

      break;
    }
    if (enemy.healthe == 0) {
      system("CLS");
      gotoxy(60 - 9, 15);
      std::cout << "You Won <Victory>";
      Sleep(1000);
      gotoxy(30, 20);
      std::cout << "[";
      looped_print_a(60, "|");
      std::cout << "]";
      Sleep(3000);
      system("CLS");
      break;
    }
    if (input == 'g')
    {
      enemy.healthe =0;
    }

    if (input == ' ') {
      system("CLS");
      break;
    }
    if (input == 27) {
      system("CLS");
      break;
    }
  }
  // system("CLS");
}

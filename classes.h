#include "supplementryFunctions.h"
#include <iostream>
#include <string>
#include <winnt.h>
// #include <iostream>
bool sheild_active = false;

class object {
public:
  object() {};

  std::string look;
  int init_posx = 15;
  int init_posy = 12;
  int health = 12;
  std::string Health = "[////////////]";
  void display() { std::cout << look; }
  void initialize_coord() { gotoxy(init_posx, init_posy); }
  void marklin() {
    gotoxy(init_posx, init_posy - 1);
    std::cout << "< " << init_posy << " >";
  }
  void clearmark() {
    gotoxy(init_posx, init_posy - 2);
    std::cout << "      ";
  }
  void walk_down() {
    init_posy = init_posy + 1;
    gotoxy(init_posx, init_posy);
    display();
    // marklin();
  }
  void walk_up() {
    init_posy = init_posy - 1;
    gotoxy(init_posx, init_posy);
    display();
    // marklin();
  }
  void clearup() {
    gotoxy(init_posx, init_posy);
    std::cout << "      ";
  }
  void cleardown() {
    gotoxy(init_posx, init_posy);
    std::cout << "      ";
  }
  void walk_right() {
    init_posx = init_posx + 6;
    gotoxy(init_posx, init_posy);
    display();
  }
  void clearright() {
    gotoxy(init_posx, init_posy);
    std::cout << "      ";
  }
  void walk_left() {
    init_posx = init_posx - 6;
    gotoxy(init_posx, init_posy);
    display();
  }
  void clearleft() {
    gotoxy(init_posx, init_posy);
    std::cout << "      ";
  }

  void laser(int size) { // ∎
    gotoxy(0, init_posy);
    looped_print(size, "—");
    gotoxy(init_posx, init_posy);
    display();
  }
  void clearlaser() {
    looped_print(120, " ");
    gotoxy(init_posx, init_posy);
  }

  void looped_print_y(int times, std::string string) {
    for (int i = 1; i < times; i++) {
      init_posy = init_posy + 1;
      gotoxy(init_posx + 10, init_posy);
      std::cout << string;
    }
  }

  void sheild() {
    sheild_active = true;
    int length = 6;
    std::string block = "▮";
    init_posy = init_posy - (length / 2);
    gotoxy(init_posx, init_posy);
    looped_print_y(length, block);
    init_posx = init_posx;
    init_posy = init_posy - (length / 2) + 1;
    gotoxy(init_posx, init_posy);
  }
};

class Enemy {
public:
  Enemy() {};

  std::string look;
  int init_posx = 120 - 15;
  int init_posy = 12;
  int healthe = 12;
  std::string Healthe = "[////////////]";
  void display() { std::cout << look; }
  void initialize_coord_e() { gotoxy(init_posx, init_posy); }
  void markline() {
    gotoxy(init_posx, init_posy - 1);
    std::cout << "< " << init_posy << " >";
  }
  void clearmarke() {
    gotoxy(init_posx, init_posy - 2);
    std::cout << "      ";
  }
  void walk_down_e() {
    init_posy = init_posy + 1;
    gotoxy(init_posx, init_posy);
    display();
    // markline();
  }
  void walk_up_e() {
    init_posy = init_posy - 1;
    gotoxy(init_posx, init_posy);
    display();
    // markline();
  }
  void clearup_e() {
    gotoxy(init_posx, init_posy);
    std::cout << "      ";
  }
  void cleardown_e() {
    gotoxy(init_posx, init_posy);
    std::cout << "      ";
  }
  void walk_right_e() {
    init_posx = init_posx + 6;
    gotoxy(init_posx, init_posy);
    display();
  }
  void clearright_e() {
    gotoxy(init_posx, init_posy);
    std::cout << "      ";
  }
  void walk_left_e() {
    init_posx = init_posx - 6;
    gotoxy(init_posx, init_posy);
    display();
  }
  void clearleft_e() {
    gotoxy(init_posx, init_posy);
    std::cout << "      ";
  }

  void laser_e(int size) { // ∎
    gotoxy(0, init_posy);
    looped_print(size, "—");
    gotoxy(init_posx, init_posy);
    display();
  }
  void clearlaser_e() {
    looped_print(120, " ");
    gotoxy(init_posx, init_posy);
  }

  void looped_print_y_e(int times, std::string string) {
    for (int i = 1; i < times; i++) {
      init_posy = init_posy + 1;
      gotoxy(init_posx + 10, init_posy);
      std::cout << string;
    }
  }

  void sheild_e() {
    sheild_active = true;
    int length = 6;
    std::string block = "▮";
    init_posy = init_posy - (length / 2);
    gotoxy(init_posx, init_posy);
    looped_print_y_e(length, block);
    init_posx = init_posx;
    init_posy = init_posy - (length / 2) + 1;
    gotoxy(init_posx, init_posy);
  }

  // evil programming

  void goTowardsplayer() {}
};
// RIP FOR 2 MONTHS

void stats() {
  gotoxy(60 - 21, 2);
  std::cout << "Welcome to the arena, fight till you die.";
  gotoxy(60 - 27, 4);
  std::cout << "use <W> and <S> keys to move vertically, and <E> to attack.";
  gotoxy(0, 5);
  std::cout << "Player1 <you>";
  gotoxy(120 - 25, 5);
  std::cout << "Player2 <bot>";
  gotoxy(0, 6);
  std::cout << "Damage: [/]";
  gotoxy(120 - 25, 6);
  std::cout << "Damage: [/]";
  gotoxy(0, 7);
  std::cout << "Health: " << object().Health;
  gotoxy(120 - 25, 7);
  std::cout << "Health: " << Enemy().Healthe;
  gotoxy(0, 8);
  std::cout << "health:   " << object().health;
  gotoxy(120 - 25, 8);
  std::cout << "health:   " << Enemy().healthe;
  gotoxy(0, 9);
  looped_print(120, "=");
}

void updateHealth(class object &p) {
  int dash = (p.health + 10) - 2;
  gotoxy(dash, 7);
  std::cout << " ";
  gotoxy(10, 8);
  std::cout << "  ";
  dash--;
  p.health--;
  gotoxy(10, 8);
  std::cout << p.health;
}
void updateHealthe(class Enemy &p) {
  int dashe = (p.healthe + 120 - 15) - 2;
  gotoxy(dashe, 7);
  std::cout << " ";

  gotoxy(120 - 15, 8);
  std::cout << "  ";
  dashe--;
  p.healthe--;
  gotoxy(120 - 15, 8);
  std::cout << p.healthe;
}



#pragma once

#include "raylib.h"

class Player {
  static const int OFFSET = 10;
  static const int WIDTH = 25;
  static const int HEIGHT = 120;
  static const int SPEED = 2;

  int score = 0;
  int x;
  int y;

  public:
    enum class Type { ONE, TWO };

    explicit Player(const Type&& type);

    int getScore() const;

    Rectangle paddle() const;

    void draw() const;

    void update();

    void cpuUpdate(const float& ballCy);

    void winPoint();

  protected:
    void moveUp();

    void moveDown();
};

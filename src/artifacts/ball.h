#pragma once

#include "raylib.h"

class Ball {
  static constexpr int SIZE = 20;
  static constexpr Color FILL = WHITE;

  int speed = 3;
  int cx;
  int cy;

  public:
    Ball(const int& cx, const int& cy);

    const void draw() const;

    const void update();
};

#pragma once

#include "raylib.h"

enum class Direction {
  DOWN,
  LEFT,
  RIGTH,
  UP,
};

class Ball {
  static const int SPEED = 3;
 
  int cx;
  int cy;
  int vx = SPEED;
  int vy = SPEED;

  public:
    static const int RADIUS = 20;

    Ball(const int& cx, const int& cy);

    Vector2 center() const;

    void draw() const;

    void update();

    void move(const Direction& direction);
};

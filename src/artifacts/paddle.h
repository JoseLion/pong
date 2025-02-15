#pragma once

#include "raylib.h"

enum class Side { LEFT, RIGHT };

class Paddle {
  const int offset = 10;
  const int width = 25;
  const int height = 120;
  const int speed = 2;

  int x;
  int y = (GetScreenHeight() / 2) - (height / 2);

  public:
    explicit Paddle(const Side& side);

    void draw() const;

    void update();
};

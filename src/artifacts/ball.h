#pragma once

class Ball {
  const int r = 20;

  int cx;
  int cy;
  int vx = 3;
  int vy = 3;

  public:
    Ball(const int& cx, const int& cy);

    const void draw() const;

    const void update();
};

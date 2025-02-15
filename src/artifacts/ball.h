#pragma once

class Ball {
  const int r = 20;

  int cx;
  int cy;
  int vx = 3;
  int vy = 3;

  public:
    Ball(const int& cx, const int& cy);

    int getCy() const;

    void draw() const;

    void update();
};

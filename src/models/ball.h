#pragma once

#include <functional>
#include "player.h"
#include "raylib.h"

enum class Direction {
  DOWN,
  LEFT,
  RIGTH,
  UP,
};

class Ball {
  using OnScore = std::function<void(const Player::Type&)>;

  static const int SPEED = 3;
 
  const OnScore onScore;
  int cx = GetScreenWidth() / 2;
  int cy = GetScreenHeight() / 2;
  int vx = SPEED;
  int vy = SPEED;

  public:
    static const int RADIUS = 20;

    explicit Ball(const OnScore&& onScore);

    Vector2 center() const;

    void draw() const;

    void update();

    void move(const Direction& direction);

  private:
    void reset();
};

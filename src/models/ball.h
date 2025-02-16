#pragma once

#include <functional>

#include "raylib.h"

#include "player.h"

enum class Direction {
  DOWN,
  LEFT,
  RIGTH,
  UP,
};

class Ball {
  using OnScore = std::function<void(const Player::Type&)>;

  static constexpr float SPEED = Player::SPEED * 1.35f;
 
  const OnScore onScore;
  float cx = static_cast<float>(GetScreenWidth()) / 2.0f;
  float cy = static_cast<float>(GetScreenHeight()) / 2.0f;
  float vx = SPEED;
  float vy = SPEED;

  public:
    static constexpr float RADIUS = 20.0f;

    explicit Ball(const OnScore&& onScore);

    Vector2 center() const;

    void draw() const;

    void update();

    void move(const Direction& direction);

  private:
    void reset();
};

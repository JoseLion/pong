#include "ball.h"

#include <functional>

#include "raylib.h"

#include "player.h"
#include "helpers/theme.h"

Ball::Ball(const OnScore&& onScore): onScore(onScore) {

}

Vector2 Ball::center() const {
  return Vector2 {
    static_cast<float>(cx),
    static_cast<float>(cy),
  };
}

void Ball::draw() const {
  DrawCircle(cx, cy, static_cast<float>(RADIUS), Theme::YELLOW_500);
}

void Ball::update() {
  using enum Direction;
  cx += vx;
  cy += vy;

  if (cx + RADIUS >= GetScreenWidth()) {
    onScore(Player::Type::ONE);
    reset();
  }

  if (cx - RADIUS <= 0) {
    onScore(Player::Type::TWO);
    reset();
  }

  if (cy + RADIUS >= GetScreenHeight()) {
    move(UP);
  }

  if (cy - RADIUS <= 0) {
    move(DOWN);
  }
}

void Ball::move(const Direction& direction) {
  switch (direction) {
    using enum Direction;
    case DOWN:
      vy = SPEED;
      break;
    case LEFT:
      vx = -SPEED;
      break;
    case RIGTH:
      vx = SPEED;
      break;
    case UP:
      vy = -SPEED;
  }
}

void Ball::reset() {
  cx = GetScreenWidth() / 2;
  cy = GetScreenHeight() / 2;
  vx = GetRandomValue(0, 1) ? SPEED : -SPEED;
  vy = GetRandomValue(0, 1) ? SPEED : -SPEED;
}

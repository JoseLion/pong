#include "ball.h"

#include <functional>

#include "raylib.h"

#include "player.h"
#include "helpers/theme.h"

Ball::Ball(const OnScore&& onScore): onScore(onScore) {

}

Vector2 Ball::center() const {
  return Vector2 { cx, cy };
}

void Ball::draw() const {
  DrawCircleV(Vector2 { cx, cy }, RADIUS, Theme::YELLOW_500);
}

void Ball::update() {
  const auto frameTime = GetFrameTime();

  cx += vx * frameTime;
  cy += vy * frameTime;

  if (cx + RADIUS >= static_cast<float>(GetScreenWidth())) {
    onScore(Player::Type::ONE);
    reset();
  }

  if (cx - RADIUS <= 0) {
    onScore(Player::Type::TWO);
    reset();
  }

  if (cy + RADIUS >= static_cast<float>(GetScreenHeight())) {
    move(Direction::UP);
  }

  if (cy - RADIUS <= 0) {
    move(Direction::DOWN);
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
  cx = static_cast<float>(GetScreenWidth()) / 2;
  cy = static_cast<float>(GetScreenHeight()) / 2;
  vx = GetRandomValue(0, 1) ? SPEED : -SPEED;
  vy = GetRandomValue(0, 1) ? SPEED : -SPEED;
}

#include "ball.h"

#include <functional>

#include "raylib.h"

#include "player.h"
#include "helpers/theme.h"

Ball::Ball(const OnScore&& onScore): onScore(onScore) {

}

Vector2 Ball::center() const {
  return Vector2 { this->cx, this->cy };
}

void Ball::draw() const {
  DrawCircleV(Vector2 { this->cx, this->cy }, RADIUS, Theme::YELLOW_500);
}

void Ball::update() {
  const auto frameTime = GetFrameTime();

  this->cx += this->vx * frameTime;
  this->cy += this->vy * frameTime;

  if (this->cx + RADIUS >= static_cast<float>(GetScreenWidth())) {
    this->onScore(Player::Type::ONE);
    this->reset();
  }

  if (this->cx - RADIUS <= 0) {
    this->onScore(Player::Type::TWO);
    this->reset();
  }

  if (this->cy + RADIUS >= static_cast<float>(GetScreenHeight())) {
    this->move(Direction::UP);
  }

  if (this->cy - RADIUS <= 0) {
    this->move(Direction::DOWN);
  }
}

void Ball::move(const Direction& direction) {
  switch (direction) {
    using enum Direction;
    case DOWN:
      this->vy = SPEED;
      break;
    case LEFT:
      this->vx = -SPEED;
      break;
    case RIGTH:
      this->vx = SPEED;
      break;
    case UP:
      this->vy = -SPEED;
      break;
  }
}

void Ball::reset() {
  this->cx = static_cast<float>(GetScreenWidth()) / 2;
  this->cy = static_cast<float>(GetScreenHeight()) / 2;
  this->vx = GetRandomValue(0, 1) ? SPEED : -SPEED;
  this->vy = GetRandomValue(0, 1) ? SPEED : -SPEED;
}

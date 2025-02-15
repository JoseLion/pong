#include "raylib.h"

#include "ball.h"

Ball::Ball(const int& cx, const int& cy): cx(cx), cy(cy) {

}

Vector2 Ball::center() const {
  return Vector2 {
    static_cast<float>(cx),
    static_cast<float>(cy),
  };
}

void Ball::draw() const {
  DrawCircle(cx, cy, static_cast<float>(RADIUS), WHITE);
}

void Ball::update() {
  using enum Direction;
  cx += vx;
  cy += vy;

  if (cx + RADIUS >= GetScreenWidth()) {
    move(LEFT);
  }

  if (cx - RADIUS <= 0) {
    move(RIGTH);
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

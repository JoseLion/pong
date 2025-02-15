#include "ball.h"
#include "raylib.h"

Ball::Ball(const int& cx, const int& cy): cx(cx), cy(cy) {
}

const void Ball::draw() const {
  DrawCircle(cx, cy, r, WHITE);
}

const void Ball::update() {
  cx += vx;
  cy += vy;

  if (cx + r >= GetScreenWidth() || cx - r <= 0) {
    vx *= -1;
  }

  if (cy + r >= GetScreenHeight() || cy - r <= 0) {
    vy *= -1;
  }
}

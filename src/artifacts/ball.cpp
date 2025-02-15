#include "raylib.h"

#include "ball.h"

Ball::Ball(const int& cx, const int& cy): cx(cx), cy(cy) {

}

int Ball::getCy() const {
  return cy;
}

void Ball::draw() const {
  DrawCircle(cx, cy, static_cast<float>(r), WHITE);
}

void Ball::update() {
  cx += vx;
  cy += vy;

  if (cx + r >= GetScreenWidth() || cx - r <= 0) {
    vx *= -1;
  }

  if (cy + r >= GetScreenHeight() || cy - r <= 0) {
    vy *= -1;
  }
}



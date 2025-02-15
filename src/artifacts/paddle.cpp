#include <algorithm>

#include "paddle.h"
#include "raylib.h"

Paddle::Paddle(const Side& side) {
  y = (GetScreenHeight() / 2) - (height / 2);

  switch (side) {
    case Side::LEFT:
      x = offset;
      break;
    case Side::RIGHT:
      x = GetScreenWidth() - width - offset;
      break;
  }
}

Paddle::~Paddle() = default;

int Paddle::getCy() const {
  return y + (height / 2);
}

Rectangle Paddle::rect() const {
  return Rectangle {
    static_cast<float>(x),
    static_cast<float>(y),
    static_cast<float>(width),
    static_cast<float>(height),
  };
}

void Paddle::draw() const {
  DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::update() {
  if (IsKeyDown(KEY_UP)) {
    moveUp();
  }

  if (IsKeyDown(KEY_DOWN)) {
    moveDown();
  }
}

void Paddle::moveUp() {
  y = std::max(y - speed, 0);
}

void Paddle::moveDown() {
  y = std::min(y + speed, GetScreenHeight() - height);
}

#include <algorithm>

#include "paddle.h"
#include "raylib.h"

Paddle::Paddle(const Side& side) {
  switch (side) {
    case Side::LEFT:
      x = offset;
      break;
    case Side::RIGHT:
      x = GetScreenWidth() - width - offset;
      break;
  }
}

void Paddle::draw() const {
  DrawRectangle(x, y, width, height, WHITE);
}

void Paddle::update() {
  if (IsKeyDown(KEY_UP)) {
    y = std::max(y - speed, 0);
  }

  if (IsKeyDown(KEY_DOWN)) {
    y = std::min(y + speed, GetScreenHeight() - height);
  }
}

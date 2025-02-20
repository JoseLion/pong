#include "player.h"

#include <algorithm>

#include "raylib.h"

Player::Player(const Type&& type) {
  this->y = (static_cast<float>(GetScreenHeight()) / 2.0f) - (HEIGHT / 2.0f);
  this->x = ([&type]() {
    switch (type) {
      case Type::ONE: return OFFSET;
      case Type::TWO: return static_cast<float>(GetScreenWidth()) - WIDTH - OFFSET;
    }
  })();
}

int Player::getScore() const {
  return score;
}

Rectangle Player::paddle() const {
  return Rectangle { x, y, WIDTH, HEIGHT };
}

void Player::draw() const {
  DrawRectangleRounded(paddle(), 0.8f, 8, WHITE);
}

void Player::update() {
  if (IsKeyDown(KEY_UP)) {
    moveUp();
  }

  if (IsKeyDown(KEY_DOWN)) {
    moveDown();
  }
}

void Player::cpuUpdate(const float& ballCy) {
  const auto&& cy = y + (HEIGHT / 2.0f);

  ballCy > cy
    ? moveDown()
    : moveUp();
}

void Player::winPoint() {
  score++;
}

void Player::moveUp() {
  y = std::max(y - (SPEED * GetFrameTime()), 0.0f);
}

void Player::moveDown() {
  y = std::min(y + (SPEED * GetFrameTime()), (float)GetScreenHeight() - HEIGHT);
}

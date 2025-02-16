#include "player.h"

#include <algorithm>

#include "raylib.h"

Player::Player(const Type&& type) {
  this->y = (GetScreenHeight() / 2) - (HEIGHT / 2);
  this->x = ([&type]() {
    switch (type) {
      case Type::ONE: return OFFSET;
      case Type::TWO: return GetScreenWidth() - WIDTH - OFFSET;
    }
  })();
}

int Player::getScore() const {
  return score;
}

Rectangle Player::paddle() const {
  return Rectangle {
    static_cast<float>(x),
    static_cast<float>(y),
    static_cast<float>(WIDTH),
    static_cast<float>(HEIGHT),
  };
}

void Player::draw() const {
  DrawRectangleRounded(paddle(), 0.8f, 0, WHITE);
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
  const auto&& cy = (float)y + (HEIGHT / 2.0f);

  ballCy > cy
    ? moveDown()
    : moveUp();
}

void Player::winPoint() {
  score++;
}

void Player::moveUp() {
  y = std::max(y - SPEED, 0);
}

void Player::moveDown() {
  y = std::min(y + SPEED, GetScreenHeight() - HEIGHT);
}

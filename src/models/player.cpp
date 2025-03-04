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
  return this->score;
}

Rectangle Player::paddle() const {
  return Rectangle { this->x, this->y, WIDTH, HEIGHT };
}

void Player::draw() const {
  DrawRectangleRounded(paddle(), 0.8f, 8, WHITE);
}

void Player::update() {
  if (IsKeyDown(KEY_UP)) {
    this->moveUp();
  }

  if (IsKeyDown(KEY_DOWN)) {
    this->moveDown();
  }
}

void Player::cpuUpdate(const float& ballCy) {
  const auto cy = this->y + (HEIGHT / 2.0f);

  ballCy > cy
    ? this->moveDown()
    : this->moveUp();
}

void Player::winPoint() {
  this->score++;
}

void Player::moveUp() {
  this->y = std::max(this->y - (SPEED * GetFrameTime()), 0.0f);
}

void Player::moveDown() {
  this->y = std::min(this->y + (SPEED * GetFrameTime()), (float)GetScreenHeight() - HEIGHT);
}

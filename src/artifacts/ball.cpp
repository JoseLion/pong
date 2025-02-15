#include "ball.h"

Ball::Ball(const int& cx, const int& cy): cx(cx), cy(cy) {
}

const void Ball::draw() const {
  DrawCircle(this->cx, this->cy, this->SIZE, this->FILL);
}

const void Ball::update() {
  this->cx += this->speed;
  this->cy += this->speed;
}

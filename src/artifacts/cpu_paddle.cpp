#include "cpu_paddle.h"
#include "paddle.h"

CpuPaddle::CpuPaddle(): Paddle(Side::RIGHT) {

}

CpuPaddle::~CpuPaddle() = default;

void CpuPaddle::update() {
  Paddle::update();
}

void CpuPaddle::update(const int& ballCy) {
  ballCy > getCy()
    ? moveDown()
    : moveUp();
}

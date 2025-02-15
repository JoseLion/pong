#include "paddle.h"

class CpuPaddle: public Paddle {

  public:
    CpuPaddle();

    ~CpuPaddle() override;

    void update() override;

    void update(const int& ballCy);
};

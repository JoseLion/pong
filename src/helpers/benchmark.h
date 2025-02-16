#pragma once

class Benchmark {
  double frameTime = 0.0;
  double totalTime = 0.0;
  int totalFrames = 0;

  public:
    void persist();

    int averageFps() const;
};

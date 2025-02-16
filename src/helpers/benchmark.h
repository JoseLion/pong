#pragma once

class Benchmark {

  double startTime = 0.0;
  double frameTime = 0.0;
  double totalTime = 0.0;
  int totalFrames = 0;

  public:
    void startFrame();

    void endFrame();

    int averageFps() const;
};

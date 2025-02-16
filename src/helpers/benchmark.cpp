#include "benchmark.h"

#include "raylib.h"

void Benchmark::startFrame() {
  startTime = GetTime();
}

void Benchmark::endFrame() {
  const auto endTime = GetTime();

  totalFrames++;
  totalTime += endTime - startTime;
  startTime = 0.0;
}

int Benchmark::averageFps() const {
  const auto averageTime = totalTime / totalFrames;

  return static_cast<int>(1.0 / averageTime);
}

#include "benchmark.h"

#include "raylib.h"

void Benchmark::persist() {
  totalTime += GetFrameTime();
  totalFrames++;
}

int Benchmark::averageFps() const {
  const auto averageTime = totalTime / totalFrames;

  return static_cast<int>(1.0 / averageTime);
}

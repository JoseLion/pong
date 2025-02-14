#include <iostream>
#include "raylib.h"

struct Screen {
  const int width = 1280;
  const int height = 800;
};

int main() {
  std::cout << "Starting game..." << std::endl;

  const auto screen = Screen();

  InitWindow(screen.width, screen.height, "Pong!");
  SetTargetFPS(120);

  while (!WindowShouldClose()) {
    BeginDrawing();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

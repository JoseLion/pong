#include <iostream>
#include "raylib.h"

struct Screen {
  const int width = 1280;
  const int height = 800;
  const int cx = this->width / 2;
  const int cy = this->height / 2;
};

int main() {
  std::cout << "Starting game..." << std::endl;

  const auto screen = Screen();

  InitWindow(screen.width, screen.height, "Pong!");
  SetTargetFPS(120);

  while (!WindowShouldClose()) {
    BeginDrawing();

    DrawLine(screen.cx, 0, screen.cx, screen.height, WHITE); 

    DrawCircle(screen.cx, screen.cy, 20, WHITE);

    DrawRectangle(10, (screen.cy) - (120 / 2), 25, 120, WHITE);
    DrawRectangle(screen.width - 25 - 10, (screen.cy) - (120 / 2), 25, 120, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

#include <iostream>
#include "raylib.h"

#include "artifacts/ball.h"

struct Screen {
  const int width = 1280;
  const int height = 800;
  const int cx = width / 2;
  const int cy = height / 2;
};

int main() {
  std::cout << "Starting game..." << std::endl;

  const auto screen = Screen();
  auto ball = Ball(screen.cx, screen.cy);

  InitWindow(screen.width, screen.height, "Pong!");
  SetTargetFPS(120);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ball.update();

    ClearBackground(BLACK);
    DrawLine(screen.cx, 0, screen.cx, screen.height, WHITE); 
    ball.draw();
    DrawRectangle(10, (screen.cy) - (120 / 2), 25, 120, WHITE);
    DrawRectangle(screen.width - 25 - 10, (screen.cy) - (120 / 2), 25, 120, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

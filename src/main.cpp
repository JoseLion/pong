#include <iostream>
#include "raylib.h"

#include "artifacts/ball.h"
#include "artifacts/paddle.h"

struct Screen {
  const int width = 1280;
  const int height = 800;
  const int cx = width / 2;
  const int cy = height / 2;
};

int main() {
  std::cout << "Starting game..." << std::endl;

  const auto screen = Screen();
  InitWindow(screen.width, screen.height, "Pong!");
  SetTargetFPS(120);

  auto ball = Ball(screen.cx, screen.cy);
  auto player1 = Paddle(Side::LEFT);
  auto player2 = Paddle(Side::RIGHT);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ball.update();
    player1.update();

    ClearBackground(BLACK);
    DrawLine(screen.cx, 0, screen.cx, screen.height, WHITE);

    ball.draw();
    player1.draw();
    player2.draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

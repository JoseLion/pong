#include <iostream>

#include "raylib.h"

#include "helpers/theme.h"
#include "models/ball.h"
#include "models/player.h"

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

  auto player1 = Player(Player::Type::ONE);
  auto player2 = Player(Player::Type::TWO);
  auto ball = Ball([&player1, &player2](const Player::Type& player) {
    switch (player) {
      case Player::Type::ONE:
        player1.winPoint();
        break;
      case Player::Type::TWO:
        player2.winPoint();
        break;
    }
  });

  while (!WindowShouldClose()) {
    BeginDrawing();

    ball.update();
    player1.update();
    player2.cpuUpdate(ball.center().y);

    if (CheckCollisionCircleRec(ball.center(), Ball::RADIUS, player1.paddle())) {
      ball.move(Direction::RIGTH);
    }

    if (CheckCollisionCircleRec(ball.center(), Ball::RADIUS, player2.paddle())) {
      ball.move(Direction::LEFT);
    }

    ClearBackground(Theme::GREEN_900);
    DrawRectangle(screen.cx, 0, screen.cx, screen.height, Theme::GREEN_500);
    DrawCircle(screen.cx, screen.cy, 150, Theme::GREEN_100);
    DrawLine(screen.cx, 0, screen.cx, screen.height, WHITE);

    ball.draw();
    player1.draw();
    player2.draw();

    DrawText(TextFormat("%i", player1.getScore()), (screen.cx / 2) - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", player2.getScore()), (3 * screen.cx / 2) - 20, 20, 80, WHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}

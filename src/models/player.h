#pragma once

#include "raylib.h"

class Player {
  static constexpr float OFFSET = 10.0f;
  static constexpr float WIDTH = 25.0f;
  static constexpr float HEIGHT = 120.0f;

  int score = 0;
  float x;
  float y;

  public:
    enum class Type { ONE, TWO };

    static constexpr float SPEED = 360.0f;

    explicit Player(const Type&& type);

    int getScore() const;

    Rectangle paddle() const;

    void draw() const;

    void update();

    void cpuUpdate(const float& ballCy);

    void winPoint();

  protected:
    void moveUp();

    void moveDown();
};

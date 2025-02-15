#pragma once

enum class Side { LEFT, RIGHT };

class Paddle {
  const int offset = 10;
  const int width = 25;
  const int height = 120;
  const int speed = 2;

  int x;
  int y;

  public:
    explicit Paddle(const Side& side);

    virtual ~Paddle();

    int getCy() const;

    void draw() const;

    virtual void update();

  protected:
    void moveUp();

    void moveDown();
};

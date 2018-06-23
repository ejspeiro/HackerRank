// Copyright 2018 Eduardo Sanchez
#include <iostream>

int main() {
  int nn{};  // Number of points.

  std::cin >> nn;

  constexpr int kMinusOne{-1};  // -1 as a constant.
  int p_x{};  // x coordinate for point p.
  int p_y{};  // x coordinate for point p.
  int q_x{};  // y coordinate for point q.
  int q_y{};  // y coordinate for point q.

  for (int ii = 1; ii <= nn; ++ii) {
    std::cin >> p_x >> p_y >> q_x >> q_y;
    // Apply translation with respect to point q.
    p_x -= q_x;
    p_y -= q_y;
    // Compute reflection point.
    p_x *= kMinusOne;
    p_y *= kMinusOne;
    // Translate back.
    p_x += q_x;
    p_y += q_y;
    std::cout << p_x << ' ' << p_y << std::endl;
  }
}

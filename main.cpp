#include <iostream>
#include <ostream>
#include <print>
#include "solver.cpp"

using namespace NonogramSolver;

Board example() {
  int32_t w = 15;
  int32_t h = 15;

  Board board = Board(w, h);

  board.set_row_restriction(0, {15});
  board.set_row_restriction(1, {5, 4, 1});
  board.set_row_restriction(2, {1, 5, 1});
  board.set_row_restriction(3, {4, 1});
  board.set_row_restriction(4, {4, 2});
  board.set_row_restriction(5, {2, 2});
  board.set_row_restriction(6, {4, 2});
  board.set_row_restriction(7, {2, 1});
  board.set_row_restriction(8, {2});
  board.set_row_restriction(9, {2, 2});
  board.set_row_restriction(10, {3, 4, 1});
  board.set_row_restriction(11, {7, 1, 2});
  board.set_row_restriction(12, {1, 2});
  board.set_row_restriction(13, {4, 2});
  board.set_row_restriction(14, {6, 4});

  board.set_col_restriction(0, {3, 2, 1, 1});
  board.set_col_restriction(1, {2, 2, 1, 1});
  board.set_col_restriction(2, {2, 1, 2, 1});
  board.set_col_restriction(3, {2, 2, 2, 1});
  board.set_col_restriction(4, {2, 2, 3, 1});
  board.set_col_restriction(5, {1, 1, 1, 1, 2});
  board.set_col_restriction(6, {1, 2, 2, 1});
  board.set_col_restriction(7, {1, 3, 1, 1});
  board.set_col_restriction(8, {4, 5});
  board.set_col_restriction(9, {4, 2, 1});
  board.set_col_restriction(10, {3, 2, 1});
  board.set_col_restriction(11, {3, 3, 2});
  board.set_col_restriction(12, {1, 2, 2});
  board.set_col_restriction(13, {1, 2, 2});
  board.set_col_restriction(14, {5, 2});

  return board;
}

void display(Board board) {
  for (int r = 0; r < board.get_height(); r++) {
    for (int c = 0; c < board.get_width(); c++) {
      std::print("{:2d} ", board.get(r, c));
    }
    std::cout << std::endl;
  }
}

int main() {
  Board board = example();

  display(board);

  solve(board);

  std::cout << "------------------------------" << std::endl;

  display(board);

  return 0;
}
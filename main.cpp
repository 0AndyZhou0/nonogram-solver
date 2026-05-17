#include <format>
#include <print>
#include "solver.cpp"

using namespace NonogramSolver;

Board example() {
  size_t w = 15;
  size_t h = 15;

  Board board = Board{w, h};

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

Board example2() {
  size_t w = 15;
  size_t h = 15;

  Board board = Board{w, h};

  board.set_row_restriction(0, {2, 2});
  board.set_row_restriction(1, {1, 2});
  board.set_row_restriction(2, {1, 3});
  board.set_row_restriction(3, {3});
  board.set_row_restriction(4, {3, 1});
  board.set_row_restriction(5, {4, 4});
  board.set_row_restriction(6, {2, 5});
  board.set_row_restriction(7, {4, 6});
  board.set_row_restriction(8, {3, 2, 1});
  board.set_row_restriction(9, {2, 1, 2});
  board.set_row_restriction(10, {2, 1, 1, 1});
  board.set_row_restriction(11, {1, 3, 1});
  board.set_row_restriction(12, {1, 1});
  board.set_row_restriction(13, {2, 2});
  board.set_row_restriction(14, {7});

  board.set_col_restriction(0, {3, 3});
  board.set_col_restriction(1, {1, 3});
  board.set_col_restriction(2, {2});
  board.set_col_restriction(3, {2});
  board.set_col_restriction(4, {1});
  board.set_col_restriction(5, {2});
  board.set_col_restriction(6, {4});
  board.set_col_restriction(7, {4});
  board.set_col_restriction(8, {6, 1});
  board.set_col_restriction(9, {3, 3, 2});
  board.set_col_restriction(10, {9});
  board.set_col_restriction(11, {4, 1, 1});
  board.set_col_restriction(12, {3, 2, 1});
  board.set_col_restriction(13, {3, 1, 2});
  board.set_col_restriction(14, {2, 8});

  return board;
}

void display(Board board) {
  for (size_t r = 0; r < board.get_height(); r++) {
    for (size_t c = 0; c < board.get_width(); c++) {
      std::print("{:2d} ", board.get(r, c));
    }
    std::print("\n");
  }
}

void test_board(Board (*func)()) {
  Board board = func();

  solve(board);
  
  display(board);

  for (size_t i = 0; i < board.get_width(); i++) {
    std::print("---");
  }
  std::print("\n");
}

int main() {
  // Board board = example();

  // // display(board);

  // solve(board);

  // for (size_t i = 0; i < board.get_width(); i++) {
  //   std::print("---");
  // }
  // std::print("\n");

  // display(board);

  // test_board(example);
  test_board(example2);
}
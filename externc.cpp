#include "solver.cpp"
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <sys/types.h>
#include <vector>

struct Solver {
  NonogramSolver::Board* board;

  Solver(size_t w, size_t h) {
    board = new NonogramSolver::Board(w, h);
  }

  ~Solver() {
    delete board;
  }
};

void set_row_restrictions(Solver* solver, size_t r, u_int32_t* restrictions, size_t size) {
  std::vector<u_int32_t> temp(size);
  for (size_t i = 0; i < size; i++) {
    temp[i] = restrictions[i];
  }
  solver->board->set_row_restriction(r, temp);
}

void set_col_restrictions(Solver* solver, size_t c, u_int32_t* restrictions, size_t size) {
  std::vector<u_int32_t> temp(size);
  for (size_t i = 0; i < size; i++) {
    temp[i] = restrictions[i];
  }
  solver->board->set_col_restriction(c, temp);
}

void solve_board(Solver* solver) {
  NonogramSolver::solve(*(solver->board));
}

int32_t get_square(Solver* solver, size_t r, size_t c) {
  return solver->board->get(r, c);
} 

int32_t* get_board(Solver* solver, int32_t* board) {
  size_t rows = solver->board->get_height();
  size_t cols = solver->board->get_width();

  for (size_t r = 0; r < rows; r++) {
    for (size_t c = 0; c < cols; c++) {
      board[(r*cols)+c] = solver->board->get(r, c);
    }
  }

  return board;
}

extern "C" {
  int test() {
    return 10;
  };
  struct Solver* get_solver(size_t w, size_t h) {
    return new Solver(w, h);
  }
  void c_set_row_restrictions(Solver* solver, size_t r, u_int32_t* restrictions, size_t size) {
    set_row_restrictions(solver, r, restrictions, size);
  }
  void c_set_col_restrictions(Solver* solver, size_t c, u_int32_t* restrictions, size_t size) {
    set_col_restrictions(solver, c, restrictions, size);
  }
  void c_solve_board(Solver* solver) {
    solve_board(solver);
  }
  int32_t c_get_square(Solver* solver, size_t r, size_t c) {
    return get_square(solver, r, c);
  }
}
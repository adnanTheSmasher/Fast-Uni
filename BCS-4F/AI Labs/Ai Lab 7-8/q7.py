import time

from ortools.sat.python import cp_model as cp, cp_model

model = cp.CpModel()

boardSize = 4
queens = [model.new_int_var(0, boardSize - 1, f"x_{i}") for i in range(boardSize)]
print(queens)

model.add_all_different(queens)
print(queens)

model.add_all_different(queens[i] + i for i in range(boardSize))
model.add_all_different(queens[i] - i for i in range(boardSize))


class NQueensSOlutionPrinter(cp_model.CpSolverSolutionCallback):

    def __init__(self, queens: list[cp_model.IntVar]):
        cp_model.CpSolverSolutionCallback.__init__(self)
        self.__queens = queens
        self.__solution_count = 0
        self.__start_time = time.time()

    @property
    def solution_count(self):
        return self.__solution_count
    def on_solution_callback(self):
        current_time = time.time()
        print(
            f"Solution {self.__solution_count}, "
            f"time = {current_time - self.__start_time} s"
        )
        self.__solution_count += 1
        allQueens = range(len(self.__queens))
        for i in allQueens:
            for j in allQueens:
                if self.value(self.__queens[j]) == i:
                    print('Q', end=" ")
                else:
                    print("_", end=" ")
            print()
        print()


solver = cp.CpSolver()
solutionprinter = NQueensSOlutionPrinter(queens)
solver.parameters.enumerate_all_solutions = True
solver.Solve(model, solutionprinter)

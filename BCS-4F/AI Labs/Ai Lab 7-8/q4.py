from ortools.sat.python import cp_model

model = cp_model.CpModel()

a = model.new_int_var(0, 3, 'a')
b = model.new_int_var(0, 3, 'b')
c = model.new_int_var(0, 3, 'c')

model.add(a != b)
model.add(b != c)
model.add(a + b <= 4)


solver = cp_model.CpSolver()
solution_printer = cp_model.VarArraySolutionPrinter([a, b, c])

solver.Solve(model, solution_printer)


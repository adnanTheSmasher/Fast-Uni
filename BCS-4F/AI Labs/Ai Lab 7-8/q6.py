from ortools.sat.python import cp_model as cp, cp_model

model = cp.CpModel()

x = model.new_int_var(0, 20, 'x')
y = model.new_int_var(0, 20, 'y')
z = model.new_int_var(0, 20, 'z')

model.add((x + (2*y) + z) <= 20)
model.add(((3*x) + y) <= 18)
model.maximize((4*x) + (2*y) + z)

solver = cp.CpSolver()
solver_printer = cp.VarArraySolutionPrinter([x, y, z])
status = solver.Solve(model, solver_printer)

print(status)
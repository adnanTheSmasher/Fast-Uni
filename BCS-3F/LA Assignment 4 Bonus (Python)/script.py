#---------------GROUP MEMBER NAMES------------
# Member 1: Adnan Hatim 24K-0656
# Member 2: Murtaza Hunaid Terai 24K-0782
# Member 3: Turab Ali Zaidi 24K-0651
#---------------------------------------------

def print_matrix(mat):
    for row in mat:
        print(["{0:8.3f}".format(x) for x in row])
    print()


def gauss_jordan_elimination(a):
    rows = len(a)
    cols = len(a[0])

    print("\nInitial Augmented Matrix:")
    print_matrix(a)

    r = 0  # current row
    for c in range(cols - 1):
        # STEP 1: Find pivot
        pivot = None
        for i in range(r, rows):
            if a[i][c] != 0:
                pivot = i
                break

        if pivot is None:
            continue  # no pivot in this column, move forward

        # STEP 2: Swap pivot row into position
        a[r], a[pivot] = a[pivot], a[r]

        print(f"After swapping rows (pivot at column {c}):")
        print_matrix(a)

        # STEP 3: Normalize pivot row (make pivot = 1)
        pivot_value = a[r][c]
        for j in range(c, cols):
            a[r][j] /= pivot_value

        print(f"After normalizing row {r}:")
        print_matrix(a)

        # STEP 4: Eliminate above and below
        for i in range(rows):
            if i != r and a[i][c] != 0:
                factor = a[i][c]
                for j in range(c, cols):
                    a[i][j] -= factor * a[r][j]

        print(f"After eliminating column {c}:")
        print_matrix(a)

        r += 1

    return a


def solving(rref):
    rows = len(rref)
    cols = len(rref[0])
    variables = cols - 1


    for row in rref:
        if all(abs(x) < 1e-9 for x in row[:-1]) and abs(row[-1]) > 1e-9:
            return "no_solution", None

    # Count pivot rows
    pivot_columns = []
    for i in range(rows):
        for j in range(variables):
            if abs(rref[i][j] - 1) < 1e-9:
                pivot_columns.append(j)
                break

    pivot_count = len(pivot_columns)


    if pivot_count == variables:
        solution = [0] * variables
        for i in range(variables):
            solution[i] = rref[i][-1]
        return "unique", solution

    # Infinite solutions
    return "infinite", pivot_columns


# -------------------------
# MAIN PROGRAM
# -------------------------

print("Gauss–Jordan Linear Equation Solver")
print("-----------------------------------")

n = int(input("Enter number of equations: "))
m = n + 1

print("\nEnter the augmented matrix (each row separated by spaces):")
matrix = []

for i in range(n):
    row = list(map(float, input(f"Row {i+1}: ").split()))
    while len(row) != m:
        print("❌ Invalid row size! Enter exactly", m, "values.")
        row = list(map(float, input(f"Row {i+1}: ").split()))
    matrix.append(row)


rref = gauss_jordan_elimination(matrix)

print("\nFinal RREF Matrix:")
print_matrix(rref)


status, result = solving(rref)

if status == "unique":
    print("✔ Unique Solution:")
    for i, val in enumerate(result):
        print(f"x{i+1} = {val:.4f}")

elif status == "no_solution":
    print("❌ No Solution (Inconsistent System)")

else:
    print("∞ Infinite Solutions:")
    print("Pivot variables at columns:", result)
    print("Free variables exist. Express in parameter form manually.")


# Unique Solution
# 1 1 -1 5
# 0 1 -5 8
# 0 0 1 -1

# No Solution
# 1 1 1  2
# 0 1 -3 1
# 2 1 5  0

# infinitley Solution
# -3 -5 36 10
# -1 0 7   5
# 1 1 -10 -4


import random

def f(x):
    return -x**2 + 6*x

def hill_climbing():
    x = random.randint(0, 10)

    step = 0

    print("=" * 45)
    print("       HILL CLIMBING ALGORITHM")
    print("    f(x) = -x^2 + 6x  |  Range: 0 ≤ x ≤ 10")
    print("=" * 45)
    print(f"\n🔹 Initial x = {x}  →  f({x}) = {f(x)}")
    print("-" * 45)

    while True:
        current_value = f(x)

        left = (x-1) if (x-1) >= 0 else None
        right = (x+1) if (x+1) <= 10 else None

        left_val = f(left) if left is not None else None
        right_val = f(right) if right is not None else None

        print(f"\nStep {step + 1}: Current x = {x}  →  f(x) = {current_value}")
        if left is not None:
            print(f"Neighbor x-1 = {left}   →  f({left}) = {left_val}")
        if right is not None:
            print(f"Neighbor x+1 = {right}   →  f({right}) = {right_val}")

        best_neighbour = None
        best_value = current_value

        if left_val is not None and left_val > best_value:
            best_value = left_val
            best_neighbour = left
        if right_val is not None and right_val > best_value:
            best_value = right_val
            best_neighbour = right
        if best_neighbour is None:
            print(f"\n No better neighbor found. Stopping.")
            break
        else:
            x = best_neighbour
            step += 1


    print("\n" + "=" * 45)
    print(f"OPTIMAL SOLUTION FOUND")
    print(f"    x = {x}")
    print(f"    f({x}) = {f(x)}")
    print("=" * 45)

if __name__ == "__main__":
    hill_climbing()
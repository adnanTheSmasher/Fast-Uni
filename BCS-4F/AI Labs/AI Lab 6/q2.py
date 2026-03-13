from types import new_class


def f(x):
    return abs(20-x)

def beam_search():
    start = 1
    goal = 20
    beam_width = 2

    beam = [(start, [start])]
    level = 0

    print("=" * 50)
    print("            BEAM SEARCH")
    print("Start = 1 | Goal = 20 | Beam width = 2")
    print("=" * 50)

    while beam:
        level += 1
        print(f"\nLevel {level}")
        candidates = []

        for number, path in beam:
            print(f"Exploring {number}")

            if number == goal:
                print("\nGoal Reached!")
                print("Path:", " -> ".join(map(str, path)))
                return

            children = [number + 2, number + 3, number * 2]
            for child in children:
                if child <= 40:
                    newPath = path + [child]
                    h = f(child)
                    candidates.append((child, newPath, h))

        candidates = sorted(candidates, key=lambda x:x[2])
        beam = [(num, path) for num, path, h in candidates[:beam_width]]

        print("Selected states for next level:")
        for num, path in beam:
            print(f"{num}  (h={f(num)})")

    print("Goal Not Found")


if __name__ == "__main__":
    beam_search()
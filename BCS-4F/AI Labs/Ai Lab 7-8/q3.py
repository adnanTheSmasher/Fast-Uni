import math

class Node:
    def __init__(self, name, value=None):
        self.value = value
        self.name = name
        self.children = []
        self.minimaxValue = None
        self.bestChild = None

def alphabeta(node, depth, alpha, beta, maximize=True):
    if depth == 0 or not node.children:
        return node.value

    if maximize:
        value = -math.inf
        for child in node.children:
            child_value = max(value, alphabeta(child, depth - 1, alpha, beta, False))
            if child_value > value:
                value = child_value
                node.bestChild = child

            alpha = max(alpha, value)
            if beta <= alpha:
                print("Pruned Node: ", child.value)
                break
        node.minimaxValue = value
        print(f"Name: {node.name}, Value: {node.value}, minimax: {node.minimaxValue}")
        return value
    else:
        value = math.inf
        for child in node.children:
            child_value = min(value, alphabeta(child, depth - 1, alpha, beta, True))
            if child_value < value:
                value = child_value
                node.bestChild = child

            beta = min(beta, value)
            if beta <= alpha:
                print("Pruned Node: ", child.value)
                break
        node.minimaxValue = value
        return value

def getOptimalPath(node):
    path = []
    while node:
        path.append(node.name)
        node = node.bestChild
    return path


root = Node('Root')

A = Node('A')
B = Node('B')

root.children = [A, B]

C = Node('C')
D = Node('D')

A.children = [C, D]

E = Node('E')
F = Node('F')

B.children = [E, F]

C1 = Node('C1', 4)
C2 = Node('C2', 4)
C.children = [C1, C2]

D1 = Node('D1', 7)
D2 = Node('D2', 8)
D.children = [D1, D2]

E1 = Node('E1', 9)
E2 = Node('E2',6)
E.children = [E1, E2]

F1 = Node('F1', 3)
F2 = Node('F2', 6)
F.children = [F1, F2]







alphabeta(root, 3, -math.inf, math.inf, True)

path = getOptimalPath(root)
print("Optimal Path:", " -> ".join(path))

print("Minimax values:")
print("Root:", root.minimaxValue)
print("A:", A.minimaxValue)
print("B:", B.minimaxValue)
print("C:", C.minimaxValue)
print("D:", D.minimaxValue)
print("E:", E.minimaxValue)
print("F:", F.minimaxValue)
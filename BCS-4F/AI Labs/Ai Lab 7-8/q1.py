import math

class Node:
    def __init__(self, value=None):
        self.value = value
        self.children = []
        self.minimaxValue = None

def minimax(node, depth, maximizing=True):
    if not node.children:
        node.minimaxValue = node.value
        return node.value

    if depth == 0:
        values = [child.value for child in node.children]
        node.minimaxValue = max(values) if maximizing else min(values)
        return node.minimaxValue

    if maximizing:
        value = -math.inf
        for child in node.children:
            childValue = minimax(child, depth-1, False)
            value = max(value, childValue)
        node.minimaxValue = value
        return value
    else:
        value = math.inf
        for child in node.children:
            childValue = minimax(child, depth-1, True)
            value = min(value, childValue)
        node.minimaxValue = value
        return value

root = Node()
root.value = 'A'

n1 = Node('B')
n2 = Node('C')

n3 = Node('D')
n4 = Node('E')
n5 = Node('F')
n6 = Node('G')

n7 = Node(4)
n8 = Node(7)
n9 = Node(2)
n10 = Node(5)
n11 = Node(1)
n12 = Node(8)
n13 = Node(3)
n14 = Node(6)


root.children = [n1, n2]

n1.children = [n3, n4]
n2.children = [n5, n6]

n3.children = [n7, n8]
n4.children = [n9, n10]
n5.children = [n11, n12]
n6.children = [n13, n14]


minimax(root, 2)
print("Minimax values:")
print("A:", root.minimaxValue)
print("B:", n1.minimaxValue)
print("C:", n2.minimaxValue)
print("D:", n3.minimaxValue)
print("E:", n4.minimaxValue)
print("F:", n5.minimaxValue)
print("G:", n6.minimaxValue)


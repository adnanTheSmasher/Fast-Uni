graph = {
'A': ['B', 'C'],
'B': ['D', 'E'],
'C': ['F'],
'D': ['G'],
'E': [],
'F': ['H'],
'G': [],
'H': []
}



def dls_search(node, goal, depth, path):
    if depth == 0:
        return False
    if node == goal:
        path.append(node)
        return True
    if node not in graph:
        return False

    for child in graph[node]:
        if dls_search(child, goal, depth - 1, path):
            path.append(node)
            return True
    return False


def iterative_deepeing(start, goal, maxDepth):
    for depth in range(maxDepth+1):
        print(f"Depth: {depth}")
        path = []
        if dls_search(start, goal, depth, path):
            print(f"Path to goal: ", "->".join(reversed(path)))
            return
        print("Goal Not Found")


startNode = 'A'
endNode = 'H'
MaxDepth = 5
iterative_deepeing(startNode, endNode, MaxDepth)

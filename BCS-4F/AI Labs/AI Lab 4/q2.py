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

startNode = 'A'
endNode = 'H'

def dls_search(graph, startPos, exitPos, depthLimit):
    visited = []
    def dfs_search(node, depth):
        if depth > depthLimit:
            return None
        visited.append(node)
        if node == exitPos:
            return visited.copy()
        for neighbor in graph[node]:
            if neighbor not in visited:
                path = dfs_search(neighbor, depth + 1)
                if path is not None:
                    return path

        visited.remove(node)

        return None

    return dfs_search(startPos, 0)

result = dls_search(graph, startNode, endNode, 2)
if result is not None:
    print(f"Path has been Found: {result}")
else:
    print(f"Path Not Found")
result = dls_search(graph, startNode, endNode, 3)
if result is not None:
    print(f"Path has been Found: {result}")
else:
    print(f"Path Not Found")




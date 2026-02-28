BUILDING = [
[1, 1, 0, 1],
[0, 1, 1, 1],
[1, 1, 0, 1],
[1, 0, 1, 1]
]

directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def create_adjacency_list(maze):
    graph = {}
    rows = len(maze)
    cols = len(maze[0])

    for i in range(rows):
        for j in range(cols):
            if maze[i][j] == 1:
                neighbours = []
                for dx, dy in directions:
                    nx, ny = i + dx, j + dy
                    if 0 <= nx < rows and 0 <= ny < cols and maze[nx][ny] == 1:
                        neighbours.append((nx, ny))
                graph[(i, j)] = neighbours
    return graph

def bfs_search(graph, startPos, exitPos):
    visited = []
    queue = []
    visited.append(startPos)
    queue.append(startPos)

    while queue:
        node = queue.pop(0)
        print(node, end=" ")

        if node == exitPos:
            return f"Goal Found!!"

        for neighbour in graph[node]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)


def main():
    graph = create_adjacency_list(BUILDING)

    startPos = (0, 0)
    exitPos = (3, 3)



    print("Following is the Breadth First Search (BFS)")
    bfs_search(graph, startPos, exitPos)

if __name__ == "__main__":
    main()

from queue import PriorityQueue

# Graph with different edge costs
graph = {
'A': {'B': 4, 'C': 3},
'B': {'E': 12, 'F': 5},
'C': {'D': 7, 'E': 10},
'D': {'E': 2},
'E': {'G': 5},
'F': {'G': 16},
'G': {},
}
heuristic = {'A': 14,'B': 12,'C': 11,'D': 6,'E': 4,'F': 11,'G': 0}

def a_star(graph, start, goal):
    frontier = [(start, 0+heuristic[start])]

    visited = set()
    gCost = {start: 0}
    cameFrom = {start: None}

    while frontier:
        frontier.sort(key=lambda x:x[1])
        currentNode, currentF = frontier.pop(0)

        if currentNode in visited:
            continue

        print(currentNode, end=" ")
        visited.add(currentNode)

        if currentNode == goal:
            path = []
            while currentNode is not None:
                path.append(currentNode)
                currentNode = cameFrom[currentNode]
            path.reverse()
            print(f"\nGoal found with A*. Path: {path}")
            return

        for neighbour, cost in graph[currentNode].items():
            newGCost = gCost[currentNode] + cost
            fCost = newGCost + heuristic[neighbour]

            if neighbour not in gCost or newGCost < gCost[neighbour]:
                gCost[neighbour] = newGCost
                cameFrom[neighbour] = currentNode
                frontier.append((neighbour, fCost))
    print("\nGoal not found")

print("\nFollowing is the A* Search:")
a_star(graph, 'A', 'G')


from heapq import heappush, heappop

graph = {
'S': [('A', 3), ('B', 6), ('C', 5)],
'A': [('D', 9), ('E', 8)],
'B': [('F', 12), ('G', 14)],
'C': [('H', 7)],
'H': [('I', 5), ('J', 6)],
'I': [('K', 1), ('L', 10), ('M', 2)],
'D': [],
'E': [],
'F': [],
'G': [],
'J': [],
'K': [],
'L': [],
'M': []
}

from heapq import heappush, heappop

def best_first_search(graph, startNode, goalNodes):
    pq = []
    heappush(pq, (0, startNode, frozenset(), [startNode]))

    visitedStates = set()

    while pq:
        cost, node, visitedGoals, path = heappop(pq)

        if node in goalNodes:
            visitedGoals = visitedGoals | {node}

        if visitedGoals == goalNodes:
            print("All goals reached!")
            print("Shortest Path:", path)
            print("Total Cost:", cost)
            return path, cost

        state = (node, visitedGoals)

        if state in visitedStates:
            continue

        visitedStates.add(state)

        for neighbour, weight in graph[node]:
            newCost = cost + weight
            newPath = path + [neighbour]
            heappush(pq, (newCost, neighbour, visitedGoals, newPath))

    print("No solution found!")
    return None

StartNode = 'S'
GoalNode = frozenset({'H', 'I', 'K'})

best_first_search(graph, StartNode, GoalNode)
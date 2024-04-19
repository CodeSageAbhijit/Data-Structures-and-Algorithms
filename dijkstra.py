def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
   

    distances[start] = 0
    print(distances)

    visited = set()

    while len(visited) < len(graph):
        min_node = None
        min_distance = float('inf')
        for node in graph:
            if node not in visited and distances[node] < min_distance:
                min_node = node
                min_distance = distances[node]

        if min_node is None:
            break

        visited.add(min_node)

        for neighbour,weight in graph[min_node].items():
            new_distance = distances[min_node] + weight
            if new_distance < distances[neighbour]:
                distances[neighbour] = new_distance

    return distances
# Example usage:
graph = {
    'A': {'B': 5, 'C': 3},
    'B': {'C': 2, 'D': 1},
    'C': {'B': 1, 'D': 4, 'E': 8},
    'D': {'E': 6},
    'E': {}
}
start_node = 'A'
shortest_distances = dijkstra(graph, start_node)
print("Shortest distances from", start_node, "to all other nodes:")
print(shortest_distances)

import heapq

def min_assembly_time(v1, v2, X, Y):
    n = len(v1)
    graph = {}
    
    # Build the graph
    for i in range(n):
        # Node names: (i, 0) for v1, (i, 1) for v2
        if i == 0:
            graph[(i, 0)] = {(i+1, 0): v1[i], (i+1, 1): v1[i] + X}
            graph[(i, 1)] = {(i+1, 0): v2[i] + Y, (i+1, 1): v2[i] + X}
        elif i == n-1:
            graph[(i, 0)] = {('end', 0): v1[i]}
            graph[(i, 1)] = {('end', 0): v2[i]}
        else:
            graph[(i, 0)] = {(i+1, 0): v1[i], (i+1, 1): v1[i] + X}
            graph[(i, 1)] = {(i+1, 0): v2[i] + Y, (i+1, 1): v2[i] + X}

    # Dijkstra's algorithm
    distances = {node: float('inf') for node in graph}
    distances[(0, 0)] = 0
    distances[(0, 1)] = 0
    pq = [(0, (0, 0)), (0, (0, 1))]
    
    while pq:
        current_dist, current_node = heapq.heappop(pq)
        
        if current_node == ('end', 0):
            return current_dist
        
        if current_dist > distances[current_node]:
            continue
        
        for neighbor, weight in graph[current_node].items():
            distance = current_dist + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    
    return min(distances[('end', 0)], distances[('end', 1)])

# Test cases
print(min_assembly_time([2, 11, 4, 4], [9, 2, 5, 11], 8, 4))  # Test case 1
print(min_assembly_time([1, 10, 1], [10, 1, 10], 1, 5))  # Test case 2
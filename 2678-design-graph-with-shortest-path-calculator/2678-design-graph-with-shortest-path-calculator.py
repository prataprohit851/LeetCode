class Graph:

    def __init__(self, n: int, edges: List[List[int]]):
        self.graph = {i: [] for i in range(n)}
        for from_node, to_node, edge_cost in edges:
            self.graph[from_node].append((to_node, edge_cost))

    def addEdge(self, edge: List[int]) -> None:
        self.graph[edge[0]].append((edge[1], edge[2]))

    def shortestPath(self, node1: int, node2: int) -> int:
        queue = [(0, node1)]
        
        distances = {node: float('inf') for node in self.graph}
        distances[node1] = 0

        while queue:
            curr_dist, curr_node = heapq.heappop(queue)
            for neighbor, edge_cost in self.graph[curr_node]:
                distance = curr_dist + edge_cost
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(queue, (distance, neighbor))
        return distances[node2] if distances[node2] != float('inf') else -1
        
        


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)
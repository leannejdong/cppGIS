#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

class Graph {
public:
    struct Edge {
        int destination;
        double weight;
    };

    using Node = std::vector<Edge>;
    using GraphMap = std::unordered_map<int, Node>;

    GraphMap nodes;

    void addEdge(int source, int destination, double weight) {
        nodes[source].push_back({destination, weight});
        nodes[destination]; // Ensure the destination node exists in the map
    }

    std::vector<int> dijkstraShortestPath(int start, int end) {
        std::unordered_map<int, double> distance;
        std::unordered_map<int, int> predecessor;
        std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<>> pq;

        distance[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            int current = pq.top().second;
            pq.pop();

            if (current == end)
                break;

            for (const Edge& edge : nodes[current]) {
                double newDist = distance[current] + edge.weight;
                if (!distance.count(edge.destination) || newDist < distance[edge.destination]) {
                    distance[edge.destination] = newDist;
                    predecessor[edge.destination] = current;
                    pq.emplace(newDist, edge.destination);
                }
            }
        }

        std::vector<int> path;
        for (int at = end; at != start; at = predecessor[at])
            path.push_back(at);
        path.push_back(start);

        std::reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    Graph graph;

    graph.addEdge(0, 1, 10.0);
    graph.addEdge(0, 2, 15.0);
    graph.addEdge(1, 2, 5.0);
    graph.addEdge(1, 3, 12.0);
    graph.addEdge(2, 3, 2.0);
    graph.addEdge(3, 4, 7.0);

    int start = 0;
    int end = 4;
    std::vector<int> shortestPath = graph.dijkstraShortestPath(start, end);

    std::cout << "Shortest Path from Node " << start << " to Node " << end << ": ";
    for (int node : shortestPath)
        std::cout << node << " ";
    std::cout << std::endl;

    return 0;
}

// Shortest Path from Node 0 to Node 4: 0 2 3 4 
// https://leanne.godbolt.org/z/xP6YofKad

/*
 Implement a graph data structure to represent a transportation network. Define nodes as locations and edges as connections between them. 
 Implement a shortest route algorithm (e.g., Dijkstra's) to find the optimal route between two points.
*/



#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source, destination;
};

// Class to represent a graph
class Graph {
    int numVertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int V) : numVertices(V) {
        adjacencyList.resize(V);
    }

    // Add an edge to the graph
    void addEdge(const Edge& edge) {
        adjacencyList[edge.source].push_back(edge.destination);
    }

    // Modified BFS to find all possible paths between two vertices
    void findAllPaths(int startVertex, int endVertex) {
        vector<bool> visited(numVertices, false);
        vector<vector<int>> paths;
        queue<pair<int, vector<int>>> q;

        q.push({startVertex, {startVertex}});

        while (!q.empty()) {
            int currentVertex = q.front().first;
            vector<int> currentPath = q.front().second;
            q.pop();

            visited[currentVertex] = true;

            if (currentVertex == endVertex) {
                paths.push_back(currentPath);
            } else {
                for (int neighbor : adjacencyList[currentVertex]) {
                    if (!visited[neighbor]) {
                        vector<int> newPath = currentPath;
                        newPath.push_back(neighbor);
                        q.push({neighbor, newPath});
                    }
                }
            }
        }

        // Print all paths
        cout << "All paths from " << startVertex << " to " << endVertex << " are:\n";
        for (const auto& path : paths) {
            for (int vertex : path) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    cout << "Enter the number of edges in the graph: ";
    cin >> numEdges;

    // Create a graph
    Graph graph(numVertices);

    cout << "Enter the edges (source and destination):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        Edge edge;
        cin >> edge.source >> edge.destination;
        graph.addEdge(edge);
    }

    int startVertex, endVertex;
    cout << "Enter the start vertex: ";
    cin >> startVertex;
    cout << "Enter the end vertex: ";
    cin >> endVertex;

    // Find all paths from startVertex to endVertex
    graph.findAllPaths(startVertex, endVertex);

    return 0;
}



//int main() {
//    // Create a graph
//    Graph graph(6);
//
//    // Add edges
//    graph.addEdge({0, 1});
//    graph.addEdge({0, 2});
//    graph.addEdge({1, 2});
//    graph.addEdge({1, 3});
//    graph.addEdge({2, 3});
//    graph.addEdge({2, 4});
//    graph.addEdge({3, 4});
//    graph.addEdge({3, 5});
//    graph.addEdge({4, 5});
//
//    // Find all paths from vertex 0 to vertex 5
//    graph.findAllPaths(0, 5);
//
//    return 0;
//}

//Enter the number of vertices in the graph: 6
//Enter the number of edges in the graph: 9
//Enter the edges (source and destination):
//0 1
//0 2
//1 2
//1 3
//2 3
//2 4
//3 4
//3 5
//4 5
//Enter the start vertex: 0
//Enter the end vertex: 5

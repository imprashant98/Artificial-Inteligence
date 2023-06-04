#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Graph class to represent the input graph
class Graph {
public:
    int numVertices;
    vector<vector<int>> adjacencyList;

    Graph(int n) : numVertices(n), adjacencyList(n) {}

    // Add an edge between two vertices
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
};

// Depth First Search algorithm
void DFS(const Graph& graph, int startVertex, vector<bool>& visited) {
    // Create a stack to store vertices to be visited
    stack<int> toVisit;

    // Push the start vertex to the stack and mark it as visited
    toVisit.push(startVertex);
    visited[startVertex] = true;

    // Continue until the stack is empty
    while (!toVisit.empty()) {
        // Pop the top vertex from the stack and print it
        int currentVertex = toVisit.top();
        toVisit.pop();
        cout << currentVertex << " ";

        // Visit all unvisited neighbors of the current vertex
        for (int neighbor : graph.adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                // Push the neighbor to the stack and mark it as visited
                toVisit.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Read the number of vertices and edges
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    // Create a graph object and add edges
    Graph graph(numVertices);
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cout << "Enter edge " << i + 1 << ": ";
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    // Choose the start vertex
    int startVertex;
    cout << "Enter the start vertex: ";
    cin >> startVertex;

    // Run the Depth First Search algorithm from the start vertex
    vector<bool> visited(numVertices, false);
    cout << "Depth First Search traversal: ";
    DFS(graph, startVertex, visited);

    return 0;
}

//Enter the number of vertices and edges: 6 7
//Enter edge 1: 0 1
//Enter edge 2: 0 2
//Enter edge 3: 1 3
//Enter edge 4: 2 3
//Enter edge 5: 2 4
//Enter edge 6: 3 4
//Enter edge 7: 3 5
//Enter the start vertex: 0


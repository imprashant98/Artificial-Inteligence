#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void printPath(vector<int>& path) {
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;
}

void BFS(vector<vector<int>>& graph, int start, int end) {
    queue<vector<int>> q;
    vector<bool> visited(graph.size(), false);

    vector<int> path;
    path.push_back(start);
    q.push(path);

    while (!q.empty()) {
        path = q.front();
        q.pop();

        int lastVertex = path.back();

        if (lastVertex == end) {
            printPath(path);
        }

        visited[lastVertex] = true;

        for (int adjacent : graph[lastVertex]) {
            if (!visited[adjacent]) {
                vector<int> newPath(path);
                newPath.push_back(adjacent);
                q.push(newPath);
            }
        }
    }
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the start and end point of each edge:\n";
    for (int i = 0; i < numEdges; i++) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
    }

    int startVertex, endVertex;
    cout << "Enter the start vertex: ";
    cin >> startVertex;
    cout << "Enter the end vertex: ";
    cin >> endVertex;

    cout << "All possible paths between " << startVertex << " and " << endVertex << ":\n";
    BFS(graph, startVertex, endVertex);

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

vector<vector<pi>> graph;

// Function for adding edges to graph
void addedge(int x, int y, int cost)
{
    graph[x].push_back(make_pair(cost, y));
    graph[y].push_back(make_pair(cost, x));
}

// Function for implementing Best First Search
// Gives output path having lowest cost
void best_first_search(int actual_Src, int target, int n)
{
    vector<bool> visited(n, false);
    // MIN HEAP priority queue
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    // sorting in pq gets done by first value of pair
    pq.push(make_pair(0, actual_Src));
    int s = actual_Src;
    visited[s] = true;
    while (!pq.empty())
    {
        int x = pq.top().second;
        // Displaying the path having lowest cost
        cout << x << " ";
        pq.pop();
        if (x == target)
            break;

        for (int i = 0; i < graph[x].size(); i++)
        {
            if (!visited[graph[x][i].second])
            {
                visited[graph[x][i].second] = true;
                pq.push(make_pair(graph[x][i].first, graph[x][i].second));
            }
        }
    }
}

// Driver code to test above methods
int main()
{
    int v, e;
    cout << "Enter the number of nodes: ";
    cin >> v;
    graph.resize(v);

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges in the format 'node1 node2 cost':\n";
    for (int i = 0; i < e; i++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        addedge(x, y, cost);
    }

    int source, target;
    cout << "Enter the source node: ";
    cin >> source;

    cout << "Enter the target node: ";
    cin >> target;

    // Function call
    best_first_search(source, target, v);

    return 0;
}

//Enter the number of nodes: 5
//Enter the number of edges: 6
//Enter the edges in the format 'node1 node2 cost':
//0 1 4
//0 2 2
//1 3 1
//1 4 6
//2 3 3
//3 4 5
//Enter the source node: 0
//Enter the target node: 4


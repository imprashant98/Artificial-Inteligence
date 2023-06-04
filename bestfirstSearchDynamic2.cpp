#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

// Node structure representing a state in the search space
struct Node {
    int state;
    int heuristic;

    Node(int s, int h) : state(s), heuristic(h) {}
};

// Comparator for the priority queue based on heuristic values
struct NodeComparator {
    bool operator()(const Node& a, const Node& b) {
        return a.heuristic > b.heuristic;
    }
};

// Function prototypes
vector<int> getNeighbors(int state);
int calculateHeuristic(int state, int goal);

// Best-First Search function
void bestFirstSearch(int start, int goal) {
    // Priority queue to store the nodes
    priority_queue<Node, vector<Node>, NodeComparator> pq;

    // Set to keep track of visited nodes
    unordered_set<int> visited;

    // Enqueue the start node
    pq.emplace(start, 0);

    while (!pq.empty()) {
        // Dequeue the node with the lowest heuristic value
        Node current = pq.top();
        pq.pop();

        // Check if the goal state is reached
        if (current.state == goal) {
            cout << "Goal state reached: " << current.state << endl;
            return;
        }

        // Add the current state to the visited set
        visited.insert(current.state);

        // Expand the current node and enqueue its neighbors
        for (int neighbor : getNeighbors(current.state)) {
            // Check if the neighbor has been visited
            if (visited.find(neighbor) == visited.end()) {
                // Calculate the heuristic value for the neighbor
                int heuristic = calculateHeuristic(neighbor, goal);

                // Enqueue the neighbor with its heuristic value
                pq.emplace(neighbor, heuristic);
            }
        }
    }

    // If the queue becomes empty, the goal state is not reachable
    cout << "Goal state not reachable" << endl;
}

// Function to get the neighbors of a given state
vector<int> getNeighbors(int state) {
    vector<int> neighbors;
    neighbors.push_back(state + 1);
    neighbors.push_back(state - 1);
    neighbors.push_back(state * 2);
    return neighbors;
}

// Function to calculate the heuristic value for a given state
int calculateHeuristic(int state, int goal) {
    return abs(goal - state);
}

int main() {
    int start, goal;
    cout << "Enter the start state: ";
    cin >> start;
    cout << "Enter the goal state: ";
    cin >> goal;

    bestFirstSearch(start, goal);

    return 0;
}

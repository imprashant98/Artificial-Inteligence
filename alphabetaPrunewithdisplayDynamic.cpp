#include <iostream>
#include <vector>
#include <limits>

struct Node {
    int value;
    std::vector<Node*> children;
};

struct PrunedBranch {
    Node* node;
    int depth;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->value = value;
    return newNode;
}

void destroyTree(Node* node) {
    if (node == nullptr)
        return;

    for (Node* child : node->children) {
        destroyTree(child);
    }

    delete node;
}

int alphaBeta(Node* node, int depth, int alpha, int beta, bool maximizingPlayer, std::vector<PrunedBranch>& prunedBranches) {
    if (depth == 0 || node->children.empty()) {
        return node->value;  // Leaf node reached, return its value
    }

    if (maximizingPlayer) {
        int maxEval = std::numeric_limits<int>::min();
        for (Node* child : node->children) {
            int eval = alphaBeta(child, depth - 1, alpha, beta, false, prunedBranches);
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                PrunedBranch prunedBranch{child, depth};
                prunedBranches.push_back(prunedBranch);  // Track pruned branch
                break;  // Beta cutoff
            }
        }
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        for (Node* child : node->children) {
            int eval = alphaBeta(child, depth - 1, alpha, beta, true, prunedBranches);
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                PrunedBranch prunedBranch{child, depth};
                prunedBranches.push_back(prunedBranch);  // Track pruned branch
                break;  // Alpha cutoff
            }
        }
        return minEval;
    }
}

int main() {
    // Create the tree structure dynamically
    Node* root = createNode(0);
    Node* node1 = createNode(3);
    Node* node2 = createNode(5);
    Node* node3 = createNode(6);
    Node* node4 = createNode(9);
    Node* node5 = createNode(1);
    Node* node6 = createNode(2);

    root->children.push_back(node1);
    root->children.push_back(node2);
    node1->children.push_back(node3);
    node1->children.push_back(node4);
    node2->children.push_back(node5);
    node2->children.push_back(node6);

    std::vector<PrunedBranch> prunedBranches;
    int result = alphaBeta(root, 3, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), true, prunedBranches);
    std::cout << "Optimal value: " << result << std::endl;

    std::cout << "Pruned branches: " << std::endl;
    for (const PrunedBranch& branch : prunedBranches) {
        std::cout << "Depth: " << branch.depth << ", Node value: " << branch.node->value << std::endl;
    }

    // Clean up the tree structure
    destroyTree(root);

    return 0;
}

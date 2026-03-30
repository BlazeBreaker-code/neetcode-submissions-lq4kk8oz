/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return dfs(node);
    }

private:
    std::unordered_map<Node*, Node*> copies;

    Node* dfs(Node* node) {
        // we want to keep traversing and setting our mapped nodes?
        if (copies.contains(node)) return copies[node];
        Node* clone = new Node(node->val);
        copies[node] = clone;
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }

        return clone;
    }
};

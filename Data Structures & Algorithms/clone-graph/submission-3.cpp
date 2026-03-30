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
        dfs(node);
        return copies[node]; // should be the root
    }

private:
    std::unordered_map<Node*, Node*> copies;

    void dfs(Node* node) {
        if (copies.contains(node)) return;

        copies[node] = new Node(node->val);
        for (Node* neighbor : node->neighbors) {
            dfs(neighbor);
            copies[node]->neighbors.push_back(copies[neighbor]);
        }
    } 
};

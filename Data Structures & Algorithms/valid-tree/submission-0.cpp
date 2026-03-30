class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // We need to figure out if this is a valid tree
        // Trees have 2 properties ->
        // no cycles
        // number of edges = n - 1
        if (edges.size() != n - 1) return false; // didn't satisfy 1st req
        vector<vector<int>> graph(n);

        for (const auto& edge : edges) {
            int a = edge[0]; // node 1
            int b = edge[1]; // node 2 

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(n, false);
        dfs(graph, visited, 0);
        for (bool seen : visited) {
            if (!seen) return false; // not all nodes are connected
        }

        return true;
    }

private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
        visited[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(graph, visited, neighbor);
            }
        }
    }
};

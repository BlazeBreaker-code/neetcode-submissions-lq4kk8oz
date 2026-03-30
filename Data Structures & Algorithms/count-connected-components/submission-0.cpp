class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // we just want to count how many different components there are 
        // component = seperate groups of nodes connected by edges
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int a = edge[0]; 
            int b = edge[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<bool> visited(n, false);
        int components = 0;
        for (int node = 0; node < n; ++node) {
            if (!visited[node]) {
                ++components;
                dfs(graph, visited, node);
            }
        }

        return components;
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

class Solution {
public:
    bool hasPath(int start, int end, vector<vector<int>>& adj, int n) {
        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == end) return true;

            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (!adj[u].empty() && !adj[v].empty()) {
                if (hasPath(u, v, adj, n)) {
                    return edge;
                }
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};

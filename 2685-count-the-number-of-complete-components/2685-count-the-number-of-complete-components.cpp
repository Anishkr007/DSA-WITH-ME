class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& nodes) {
        vis[node] = 1;
        nodes.push_back(node);

        for (auto next : adj[node]) {
            if (!vis[next]) {
                dfs(next, adj, vis, nodes);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> nodes;
                dfs(i, adj, vis, nodes);

                int k = nodes.size();
                int degreeSum = 0;

                for (int node : nodes) {
                    degreeSum += adj[node].size();
                }

                int edgeCount = degreeSum / 2;

                if (edgeCount == k * (k - 1) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
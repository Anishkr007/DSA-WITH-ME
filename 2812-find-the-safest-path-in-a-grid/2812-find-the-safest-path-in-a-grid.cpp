class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<int,int>> q;

        // Multi-source BFS from all thieves
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;

                if (dist[nr][nc] != -1)
                    continue;

                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }

        // Max heap:
        // {safeness, row, col}
        priority_queue<vector<int>> pq;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        pq.push({dist[0][0], 0, 0});
        vis[0][0] = 1;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int safe = cur[0];
            int r = cur[1];
            int c = cur[2];

            if (r == n - 1 && c == n - 1)
                return safe;

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                    continue;

                if (vis[nr][nc])
                    continue;

                int newSafe = min(safe, dist[nr][nc]);

                vis[nr][nc] = 1;
                pq.push({newSafe, nr, nc});
            }
        }

        return 0;
    }
};
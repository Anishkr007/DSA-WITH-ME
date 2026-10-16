class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};

        if (r < 0 || c < 0 || r >= n || c >= m || board[r][c] != 'O')
            return;

        board[r][c] = '#';

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            dfs(nr, nc, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            dfs(i, 0, board);
            dfs(i, m - 1, board);
        }

        for (int j = 0; j < m; j++) {
            dfs(0, j, board);
            dfs(n - 1, j, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        // Add boundary O cells to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    && board[i][j] == 'O') {
                    q.push({i, j});
                    board[i][j] = 'T';
                }
            }
        }

        // BFS to mark all boundary-connected O cells
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                if (board[nr][nc] != 'O')
                    continue;

                board[nr][nc] = 'T';
                q.push({nr, nc});
            }
        }

        // Capture surrounded O cells and restore safe cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty() && fresh > 0) {
            int sz = q.size();

            for (int s = 0; s < sz; s++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int r = i + dx[k];
                    int c = j + dy[k];

                    if (r < 0 || c < 0 || r >= n || c >= m)
                        continue;

                    if (grid[r][c] != 1)
                        continue;

                    grid[r][c] = 2;
                    fresh--;

                    q.push({r, c});
                }
            }

            time++;
        }

        if (fresh == 0)
            return time;

        return -1;
    }
};
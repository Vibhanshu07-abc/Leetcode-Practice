class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = 0, sc = 0;
        int litterCount = 0;

        // id[r][c] = bit number for litter at (r,c)
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                }
                else if (classroom[r][c] == 'L') {
                    id[r][c] = litterCount++;
                }
            }
        }

        if (litterCount == 0)
            return 0;

        int totalMasks = 1 << litterCount;
        int fullMask = totalMasks - 1;

        /*
            State:
            (r, c, energyLeft, mask)

            mask:
              1 = litter still needs to be collected
              0 = litter already collected

            We start with all bits = 1.
        */

        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, energy, fullMask});
        vis[sr][sc][energy][fullMask] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected.
                if (mask == 0)
                    return moves;

                // Cannot move without energy.
                if (e == 0)
                    continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // X is an obstacle.
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = e - 1;
                    int newMask = mask;

                    // R resets energy to full.
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Collect litter.
                    if (classroom[nr][nc] == 'L') {
                        newMask &= ~(1 << id[nr][nc]);
                    }

                    if (!vis[nr][nc][newEnergy][newMask]) {
                        vis[nr][nc][newEnergy][newMask] = true;
                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};
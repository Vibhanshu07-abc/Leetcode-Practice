class DisjointSet {
    vector<int> par, sz;

public:
    DisjointSet(int n) {
        par.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int findUPar(int node) {
        if (par[node] == node)
            return node;

        return par[node] = findUPar(par[node]);
    }

    void unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);

        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);

        par[v] = u;
        sz[u] += sz[v];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0, maxCol = 0;

        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);

        vector<int> used(maxRow + maxCol + 2, 0);

        for (auto it : stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1;

            ds.unionBySize(row, col);

            used[row] = 1;
            used[col] = 1;
        }

        int components = 0;

        for (int i = 0; i < used.size(); i++) {
            if (used[i] && ds.findUPar(i) == i)
                components++;
        }

        return n - components;
    }
};
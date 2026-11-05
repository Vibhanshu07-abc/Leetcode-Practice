class Solution {
public:
    vector<int> par, rank;

    int find(int node) {
        if (par[node] == node) {
            return node;
        }
        return par[node] = find(par[node]);
    }

    void unionfind(int x, int y) {
        int ul_u = find(x);
        int ul_v = find(y);

        if (ul_u == ul_v) return;

        if (rank[ul_u] < rank[ul_v]) {
            par[ul_u] = ul_v;
        }
        else if (rank[ul_u] > rank[ul_v]) {
            par[ul_v] = ul_u;
        }
        else {
            par[ul_u] = ul_v;
            rank[ul_v]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        par.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            par[i] = i;
        }

        vector<pair<int, pair<int,int>>> edges;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int wt = abs(points[i][0] - points[j][0])
                       + abs(points[i][1] - points[j][1]);

                edges.push_back({wt, {i, j}});
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end());

        int mst = 0;
        int count = 0;

        // Kruskal's algorithm
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (find(u) != find(v)) {
                unionfind(u, v);
                mst += wt;
                count++;

                if (count == n - 1) break;
            }
        }

        return mst;
    }
};
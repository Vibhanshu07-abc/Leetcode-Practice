class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        vector<vector<int>> dis(n, vector<int>(k + 2, INT_MAX));

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({wt, v});
        }

        dis[src][0] = 0;
        pq.push({0, {src, 0}});

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int count = pq.top().second.second;
            pq.pop();

            if (wt > dis[node][count]) continue;

            if (node == dst) return wt;

            if (count == k + 1) continue;

            for (auto it : adj[node]) {
                int nwt = it.first;
                int neigh = it.second;

                int newCost = wt + nwt;
                int newCount = count + 1;

                if (dis[neigh][newCount] > newCost) {
                    dis[neigh][newCount] = newCost;
                    pq.push({newCost, {neigh, newCount}});
                }
            }
        }

        return -1;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        vector<int>dis(n,INT_MAX);

       queue<pair<int,pair<int,int>>>pq;

        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({wt, v});
        }

        dis[src] = 0;
        pq.push({0, {src, 0}});

        while (!pq.empty()) {
            int wt = pq.front().first;
            int node = pq.front().second.first;
            int count = pq.front().second.second;
            pq.pop();
            if(count>=k+1)continue;
            for (auto it : adj[node]) {
                int nwt = it.first;
                int neigh = it.second;

                int newCost = wt + nwt;
                int newCount = count + 1;

                if (dis[neigh]> newCost) {
                    dis[neigh] = newCost;
                    pq.push({newCost, {neigh, newCount}});
                }
            }
        }
        if(dis[dst]==INT_MAX)return-1;

        return dis[dst];
    }
};
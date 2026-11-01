class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double,int>>>adj(n);
        vector<double>dis(n,-1);
       for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];

    adj[u].push_back({succProb[i], v});
    adj[v].push_back({succProb[i], u});
}
        priority_queue<pair<double,int>,vector<pair<double,int>>,less<pair<double,int>>>q;
        q.push({1,start_node});
        dis[start_node]=1;
        while(!q.empty()){
            int node=q.top().second;
            double p=q.top().first;
            q.pop();
            if (p < dis[node]) continue;
            for(auto it : adj[node]){
                double nwt=it.first;
                int neighbour=it.second;
                if(dis[neighbour]<nwt*p){
                    dis[neighbour]=nwt*p;
                    q.push({dis[neighbour],neighbour});
                }
            }
        }
        if(dis[end_node]==-1)return 0;
        return dis[end_node];
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it :times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        dis[k]=0;
        while(!q.empty()){
            int wt=q.top().first;
            int node=q.top().second;
            q.pop();
             if(wt>dis[node])continue;
             for(auto it:adj[node]){
                int neighbour=it.first;
                int nwt=it.second;
                if(dis[neighbour]>wt+nwt){
                    dis[neighbour]=wt+nwt;
                    q.push({dis[neighbour],neighbour});
                }
             }
        }
        int time=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX){return -1;}
            time=max(time,dis[i]);
        }
        return time;
        
    }
};
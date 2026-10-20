class Solution {
public:
        bool bfs(int n,vector<vector<int>>&adj,int source,int dest){
            vector<int>vis(n+1,0);
            queue<int>q;
            vis[source]=1;
            q.push(source);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            if(vis[dest]==1){
                return true;
            }
            return false;
        }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
           vector<vector<int>>adj(n+1);
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
          return bfs(n,adj,source,destination);
    }
};
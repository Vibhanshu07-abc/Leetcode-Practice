class Solution {
    private :
       void dfs(vector<vector<int>>&adj,vector<int>&vis,int node){
            vis[node]=1;
            for(auto it : adj[node]){
                if(!vis[it]){
                    dfs(adj,vis,it);
                }
            }
       }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=j&&isConnected[i][j]!=0){
                adj[i].push_back(j);
            }
        }
        }
        vector<int>vis(n+1,0);
        int count=0;
        for(int i=0;i<n;i++){
           if(!vis[i]){
            count++;
            dfs(adj,vis,i);
           }
        }
        return count;
    }
};
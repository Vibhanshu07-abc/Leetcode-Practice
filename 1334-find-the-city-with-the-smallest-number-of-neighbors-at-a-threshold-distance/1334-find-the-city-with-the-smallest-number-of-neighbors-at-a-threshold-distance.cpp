class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int>count(n,0);
         vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        for(auto it :edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            dis[u][v]=wt;
            dis[v][u]=wt;
        }
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)dis[i][j]=0;
        }
        }
        for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(dis[i][k]!=INT_MAX&&dis[k][j]!=INT_MAX){
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
          }
        }
        }
        }
     
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dis[i][j]<=distanceThreshold&&i!=j){
                count[i]++;
            }
        }
        }
      int min=count[0];
        int minidx=0;
        for(int i=1;i<n;i++){
           if(count[i]<=min){
            min=count[i];
            minidx=i;
           }
        }
       
        return minidx;
    }
};
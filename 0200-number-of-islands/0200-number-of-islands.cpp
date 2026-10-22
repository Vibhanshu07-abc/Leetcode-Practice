class Solution {
    void dfs (vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j){
           if(i>=grid.size()|| i<0||j>=grid[0].size()||j<0)return;
           if(vis[i][j]==1||grid[i][j]=='0')return;
             vis[i][j]=1;
            dfs(grid,vis,i-1,j);
            dfs(grid,vis,i+1,j);
            dfs(grid,vis,i,j-1);
            dfs(grid,vis,i,j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
         int n=grid.size();int m=grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         int count=0;
         for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(grid[i][j]=='1'&&vis[i][j]==0){
                count++;
                dfs(grid,vis,i,j);
            }
         }
         }
         return count;
    }
};
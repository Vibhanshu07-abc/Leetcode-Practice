class Solution {
    void dfs(vector<vector<int>>&image,vector<vector<int>>&vis,int i,int j,int color,int original){
         if(i<0||i>=image.size()||j<0||j>=image[0].size())return;
         if(vis[i][j]==1||image[i][j]!=original)return;
         vis[i][j]=1;
         image[i][j]=color;
         dfs(image,vis,i-1,j,color,original);
         dfs(image,vis,i+1,j,color,original);
         dfs(image,vis,i,j-1,color,original);
         dfs(image,vis,i,j+1,color,original);

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(image,vis,sr,sc,color,image[sr][sc]);
        return image;
    }
};
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
            if(i==0||i==n-1||j==0||j==m-1){
                q.push({i,j});
                grid[i][j]=2;
            }else{
                count++;
            }
            }
        }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
              q.pop();
              for(int i=0;i<4;i++){
                int rx=r+dx[i];
                int cx=c+dy[i];
                if(rx<0||rx>=n||cx<0||cx>=m||grid[rx][cx]!=1)continue;
                grid[rx][cx]=2;
                 count--;
                 q.push({rx,cx});
              }
        }
        return count;
    }
};
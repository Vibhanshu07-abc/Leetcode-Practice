class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();int m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]==1)return -1;
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        grid[0][0]=1;
       int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
       int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            if (r == n-1 && c == m-1) return dis;
            for(int i=0;i<8;i++){
                int rx=r+dx[i];
                int cx=c+dy[i];
                if(rx<0||rx>=n||cx<0||cx>=m||grid[rx][cx]!=0)continue;
                 q.push({{rx,cx},dis+1});
                 grid[rx][cx]=1;
            }
        }
        return -1;

    }
};
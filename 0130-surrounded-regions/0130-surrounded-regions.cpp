class Solution {
public:
    void solve(vector<vector<char>>& board) {
      int n=board.size();int m=board[0].size();
      int dx[]={-1,1,0,0};
      int dy[]={0,0,-1,1};
      vector<vector<int>>vis(n,vector<int>(m,0));
      queue<pair<int,int>>q;
      for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(i==0||j==0||i==n-1||j==m-1){
        if(board[i][j]=='O'&&!vis[i][j]){
          q.push({i,j});
          vis[i][j]=1;
        }
        }
    }
      }
      while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
         for(int i=0;i<4;i++){
            int x=r+dx[i];
            int y=c+dy[i];
           if(x>=n||y>=m||x<0||y<0||board[x][y]=='X'||vis[x][y]){
            continue;
           }
           vis[x][y]=1;
           q.push({x,y});
         }
      }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0){
               board[i][j]='X';
            }
        }
       }
    }
};
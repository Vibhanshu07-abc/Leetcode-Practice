class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();int m=mat[0].size();
        vector<vector<int>>nearest(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                nearest[i][j]=0;
            }
         }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dis=q.front().second;
            q.pop();
              for(int i=0;i<4;i++){
                int rx=r+dx[i];
                int cy=c+dy[i];
                if(rx<0||cy<0||rx>=n||cy>=m||nearest[rx][cy]!=-1||mat[rx][cy]==0)continue;
                 q.push({{rx,cy},dis+1});
                 nearest[rx][cy]=dis+1;
              }
        }
        return nearest;
    }
};
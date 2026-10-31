class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        if (heights.empty()) return 0;
        int m = heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        dis[0][0]=0;
        pq.push({0,0,0});
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!pq.empty()){
            int wt=pq.top()[0];
            int row=pq.top()[1];
            int col=pq.top()[2];
            pq.pop();
            if(wt>dis[row][col])continue;
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow<0||nrow>=n||ncol<0||ncol>=m){
                    continue;
                }
                int nwt=abs(heights[row][col]-heights[nrow][ncol]);
                int d=max(wt,nwt);
                if(dis[nrow][ncol]>d){
                   dis[nrow][ncol]=d;
                   pq.push({d,nrow,ncol});
                }
            }
        }
        return dis[n-1][m-1];
    
    }
};
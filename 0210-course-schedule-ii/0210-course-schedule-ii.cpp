class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ind(numCourses,0);
        vector<vector<int>>adj(numCourses);
        vector<int>sol;
        queue<int>q;
        for(auto it : prerequisites){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            ind[u]++;
        }
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            sol.push_back(node);
            for(auto it :adj[node]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        if(sol.size()==numCourses)return sol;
        return {};
    }
};
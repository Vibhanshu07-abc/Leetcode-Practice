class Solution {
    vector<int>par,sz;
    int find(int node){
        if(par[node]==node)return node;
        return par[node]=find(par[node]);
    }
    void unionfind(int u,int v){
        int ulu=find(u);
        int ulv=find(v);
        if(ulu==ulv)return;
        if(sz[ulv]<sz[ulu]) swap(ulu,ulv);
        par[ulu]=ulv;
        sz[ulv]+=sz[ulu];
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        int a=-1;
        int b=-1;
          par.resize(n);
          sz.assign(n,1);
          for(int i=0;i<n;i++){
            par[i]=i;
          }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(find(u)==find(v)){
                a=u;
                b=v;
            }else{
            unionfind(u,v);
            }
        }
        return {a,b};

    }
};
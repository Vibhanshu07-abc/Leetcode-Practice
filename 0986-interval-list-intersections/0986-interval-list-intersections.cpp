class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {  
         int aptr=0;
         int bptr=0;
        vector<vector<int>>res;
         vector<int>temp(2);
         while(aptr<A.size()&&bptr<B.size()){
            if(A[aptr][1]>=B[bptr][0]&&B[bptr][1]>=A[aptr][0]){
                temp[0]=max(A[aptr][0],B[bptr][0]);
                temp[1]=min(A[aptr][1],B[bptr][1]);
                res.push_back(temp);
            }
            if(A[aptr][1]>B[bptr][1])bptr++;
            else 
            aptr++;
         }
         return res;
        
    }
};
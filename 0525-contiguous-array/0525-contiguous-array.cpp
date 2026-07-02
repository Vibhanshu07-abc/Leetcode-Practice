class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int currentsum=0;
        int len=0;
        for(int i=0;i<nums.size();i++){
           nums[i]==0?currentsum--:currentsum++;
           if(mpp.find(currentsum)!=mpp.end()){
               len=max(len,i-mpp[currentsum]);
           }else{
           mpp[currentsum]=i;}
          
        }
        return len;
    }
};
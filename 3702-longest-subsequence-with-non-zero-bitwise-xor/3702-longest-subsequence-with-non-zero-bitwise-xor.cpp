class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int num=0;
       int n=nums.size();
       for(int i=0;i<nums.size();i++){
         num=num^nums[i];
       }
       if(num!=0)return n;
       int i=0;
       for(int i=0;i<n;i++){
        if(nums[i]!=0){
            return n-1;
        }
       }
       return 0;
    }
};
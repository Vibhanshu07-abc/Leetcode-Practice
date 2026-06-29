class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long prefix=1;
        long suffix=1;
        long maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;
            prefix*=nums[i];
            suffix*=nums[nums.size()-i-1];
              maxsum=max(maxsum,max(prefix,suffix));
        }
        
        return (int)maxsum;
    }
};
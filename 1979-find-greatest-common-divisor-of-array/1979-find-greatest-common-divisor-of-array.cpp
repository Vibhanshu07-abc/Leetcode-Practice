class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largest=nums[0];
        int smallest=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<smallest){
                smallest=nums[i];
            }
            if(nums[i]>largest){
                largest=nums[i];
            }
        }
        int result=1;
        for(int i=2;i<=smallest;i++){
          if(smallest%i==0 && largest%i==0){
           result=i;
          }
        }
        return result;
    }
};
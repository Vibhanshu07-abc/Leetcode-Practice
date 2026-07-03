class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long>sum(nums.size(),0);
        deque<int>dq;
        int j=0;
        int result=INT_MAX;
        while(j<nums.size()){
            if(j==0){
                sum[j]=nums[j];
            }else{
                sum[j]=sum[j-1]+nums[j];
            }
            if(sum[j]>=k){
                result=min(result,j+1);
            }
            while(!dq.empty()&&sum[j]-sum[dq.front()]>=k){
                result=min(result,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty()&&sum[j]<=sum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
             j++;
        }
        return result==INT_MAX?-1:result;
    }
};
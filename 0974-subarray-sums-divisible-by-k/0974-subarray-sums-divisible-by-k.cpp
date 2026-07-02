class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int prefixsum = 0;
        mp[0] = 1;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixsum += nums[i];

            int rem = ((prefixsum % k) + k) % k;   

            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }
            mp[rem]++;                         
        }

        return count;
    }
};
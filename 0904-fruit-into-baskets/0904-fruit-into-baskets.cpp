class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int l = 0, r = 0;
        int maxlen = 0;
        map<int, int> mp;
        while (r < nums.size()) {
            mp[nums[r]]++;
            while (mp.size() > 2) {
                mp[nums[l]]--;

                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
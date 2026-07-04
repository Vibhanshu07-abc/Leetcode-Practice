class Solution {
public:
    int mergeSort(vector<long long>& prefix, int left, int right, int lower, int upper) {
        if (right - left <= 1) return 0;
        int mid = (left + right) / 2;
        int count = mergeSort(prefix, left, mid, lower, upper)
                  + mergeSort(prefix, mid, right, lower, upper);
        int low = mid, high = mid;
        for (int i = left; i < mid; i++) {
            while (low < right && prefix[low] - prefix[i] < lower)
                low++;
            while (high < right && prefix[high] - prefix[i] <= upper)
                high++;
            count += high - low;
        }
        inplace_merge(prefix.begin() + left,
                      prefix.begin() + mid,
                      prefix.begin() + right);
        return count;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];

        return mergeSort(prefix, 0, prefix.size(), lower, upper);
    }
};
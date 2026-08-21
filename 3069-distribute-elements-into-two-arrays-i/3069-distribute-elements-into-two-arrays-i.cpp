class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1;
        vector<int> arr2;

        int a1 = nums[0];
        int a2 = nums[1];

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (a1 > a2) {
                arr1.push_back(nums[i]);
                a1 = nums[i];
            } else {
                arr2.push_back(nums[i]);
                a2 = nums[i];
            }
        }

        for (int x : arr2)
            arr1.push_back(x);

        return arr1;
    }
};
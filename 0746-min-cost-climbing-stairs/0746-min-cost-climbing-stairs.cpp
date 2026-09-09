class Solution {
public:
    int helper(vector<int>& cost, int pos, vector<int>& dp) {
        if (pos >= cost.size())
            return 0;

        if (dp[pos] != -1)
            return dp[pos];

        dp[pos] = cost[pos] + min(
            helper(cost, pos + 1, dp),
            helper(cost, pos + 2, dp)
        );

        return dp[pos];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);

        return min(
            helper(cost, 0, dp),
            helper(cost, 1, dp)
        );
    }
};
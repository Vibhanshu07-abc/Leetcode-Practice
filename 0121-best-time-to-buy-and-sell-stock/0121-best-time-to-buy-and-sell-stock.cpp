class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
         int minprice=INT_MAX;
         for(auto it:prices){
            minprice=min(minprice,it);
            profit=max(profit,it-minprice);
         }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mincost = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (mincost > prices[i]) {
                mincost = prices[i];
            } else if ((prices[i] - mincost) > profit) {
                profit = prices[i] - mincost;
            }
        }

        return profit;
    }
};
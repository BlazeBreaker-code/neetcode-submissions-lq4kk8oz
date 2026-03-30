class Solution {
    // Integer Arr of prices where price[i] = stock on the ith day
    // Greedy we can just keep taking
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] < prices[i]) profit += (prices[i] - prices[i - 1]);
        }

        return profit;
    }
};
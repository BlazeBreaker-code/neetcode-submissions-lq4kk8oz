class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // we need the max profit possible. 
        // for that we need the lowest price to use as our base
        int minPrice = INT_MAX, maxProfit = 0; 
        for (int price : prices) {
            minPrice = std::min(minPrice, price);
            maxProfit = std::max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // Initialize minimum price to a very large value
        int maxProfit = 0;        // Initialize maximum profit to zero
        int currentProfit = 0;    // Initialize current profit to zero
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];   // Update minimum price if a lower price is found
            }
            currentProfit = prices[i] - minPrice;   // Calculate current profit
            if(maxProfit < currentProfit){
                maxProfit = currentProfit;   // Update maximum profit if current profit is higher
            }
        }
        return maxProfit;
    }
};

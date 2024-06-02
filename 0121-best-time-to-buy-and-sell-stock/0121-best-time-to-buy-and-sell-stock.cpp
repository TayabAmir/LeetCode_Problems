class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_price = prices[0],profit = 0;
        for(int i=1;i<prices.size();i++)
        {
            current_price = min(current_price,prices[i]);
            profit = max(profit,prices[i]-current_price);
        }
        return profit;
    }
};
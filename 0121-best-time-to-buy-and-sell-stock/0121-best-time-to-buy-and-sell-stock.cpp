class Solution {
public:
    int maxProfit(vector<int>& p) {
        int curr = INT_MAX, profit = 0;
        for(int i = 0; i < p.size(); ++i)
            (p[i] < curr) ? curr = p[i] : profit = max(profit, p[i] - curr);
        return profit;
    }
};
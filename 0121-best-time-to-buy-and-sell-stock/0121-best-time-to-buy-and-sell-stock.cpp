class Solution {
public:
    int maxProfit(vector<int>& p) {
        int curr = p[0], profit = 0;
        for(int i = 1; i < p.size(); i++){
            if(p[i] > curr){
                profit = max(profit, p[i] - curr);
            } else {
                curr = p[i];
            }
        }
        return profit;
    }
};
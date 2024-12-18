class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for(int i = 0; i < prices.size(); i++){
            int minIdx = i;
            for(int j = i+1; j < prices.size(); j++){
                if(prices[j] <= prices[minIdx]){
                    minIdx = j; break;
                }
            }
            if(minIdx != i)
                prices[i] -= prices[minIdx];
        }
        return prices;
    }
};
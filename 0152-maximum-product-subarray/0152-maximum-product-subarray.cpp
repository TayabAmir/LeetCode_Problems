class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = *max_element(nums.begin(), nums.end()), currMax = 1, currMin = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                int a = currMax * nums[i], b = currMin * nums[i];
                currMax = max({a,b,nums[i]});
                currMin = min({a,b,nums[i]});
                maxProd = max({maxProd, currMax, currMin});
            } else currMax = 1, currMin = 1;
        }
        return maxProd;
    }
};
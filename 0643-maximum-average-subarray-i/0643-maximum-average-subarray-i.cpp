class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for(int i = 0; i < k; ++i)
            sum += nums[i];
        double maxAvg = sum / k;
        for(int i = k, j = 0; i < nums.size(); ++i)
            sum = sum + nums[i] - nums[j++], maxAvg = max(maxAvg, sum / k);
        return maxAvg;
    }
};
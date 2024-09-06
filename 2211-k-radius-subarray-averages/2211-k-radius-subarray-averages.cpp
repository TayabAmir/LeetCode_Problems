class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avgs(nums.size(),-1);
        if(2*k+1 > nums.size()) return avgs;

        long long sum = 0;
        for(int i = 0; i <= 2*k; ++i)
            sum += nums[i];
        int divisor = 2*k+1;
        for(int i = k; i < nums.size() - k; ++i){
            avgs[i] = sum / divisor;
            sum -= nums[i-k];
            if(i+k+1 < nums.size())
                sum += nums[i+k+1];
        }
        return avgs;
    }
};
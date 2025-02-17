class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0], maxSum = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                sum += nums[i];
            } else {
                maxSum = max(sum, maxSum);
                sum = nums[i];
            }
        }
        return max(sum,maxSum);
    }
};
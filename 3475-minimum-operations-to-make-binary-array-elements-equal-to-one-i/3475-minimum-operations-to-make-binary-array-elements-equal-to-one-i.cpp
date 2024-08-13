class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size()-2; ++i){
            if(nums[i] == 0){
                count++;
                nums[i] = nums[i] ^ 1;
                nums[i+1] = nums[i+1] ^ 1;
                nums[i+2] = nums[i+2] ^ 1;
            }
        }
        for(int i : nums)
            if(i != 1) return -1;
        return count;
    }
};
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int med = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        med = nums[n/2];

        int out = 0;
        for(int ele : nums)
            out += abs(ele-med);
        return out;
        // [1,2,3,4,5,6]
    }
};
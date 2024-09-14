class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end()), maxAnd = -1, i = 0, j;
        while(i < nums.size()){
            j = i+1;
            while(j < nums.size() && nums[j] == nums[i]) j++;
            if(nums[i] == maxEle)
                maxAnd = max(maxAnd, j-i);
            i = j;
        }
        return maxAnd;
    }
};
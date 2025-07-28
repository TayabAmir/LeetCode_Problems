class Solution {
public:
    int count(int lvl, int curr, int maxi, vector<int> &nums){
        if(lvl == nums.size()) return curr == maxi;
        return count(lvl+1, (curr | nums[lvl]), maxi, nums) + count(lvl+1, curr, maxi, nums);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            maxi |= nums[i];
        }
        return count(0, 0, maxi, nums);
    }
};
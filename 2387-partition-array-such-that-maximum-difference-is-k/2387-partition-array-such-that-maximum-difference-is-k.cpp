class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), o = 0, currLast = n - 1;
        
        for(int i = n-1; i >= 0; i--){
            if(nums[currLast] - nums[i] > k){
                o++;
                currLast = i;
            }
        }
        return o + 1;
    }
};
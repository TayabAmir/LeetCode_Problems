class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> pref(nums.size());
        pref[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) 
            pref[i] = pref[i-1] + nums[i];
        int count = 0;
        for(int i = 0; i < nums.size()-1; i++){
            if(pref[i]>=pref[nums.size()-1] - pref[i]) count++;
        }
        return count;
    }
};
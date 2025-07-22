class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        int maxi = -1, curr = 0;
        map<int,int> mp;
        while(r < n){
            if(mp.find(nums[r]) != mp.end() && l <= mp[nums[r]] && mp[nums[r]] <= r){
                while(nums[l] != nums[r]){
                    curr -= nums[l], l++;
                }
                l++;
                mp[nums[r]] = r;
            } else {
                mp[nums[r]] = r;
                curr += nums[r];
            }
            maxi = max(curr, maxi);
            r++;
        }
        return maxi;
    }
};
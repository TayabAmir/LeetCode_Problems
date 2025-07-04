class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp = {{0,1}};
        int o = 0;
        for(int i = 0, pre = 0; i < nums.size(); ++i)
            pre += nums[i], o += mp[pre-k], mp[pre]++;
        return o;
    }
};
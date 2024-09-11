class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        set<pair<int, pair<int, int>>> s;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0 && s.find({nums[i],{nums[j],nums[k]}}) == s.end()) {
                    s.insert({nums[i],{nums[j],nums[k]}});
                    triplets.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else
                    j++;
            }
        }
        return triplets;
    }
};
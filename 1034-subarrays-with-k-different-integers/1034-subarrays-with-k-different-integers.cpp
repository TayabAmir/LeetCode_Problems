class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        function<int(int)> fn = [&](int x) -> int {
            int l = 0, r = 0;
            int cnt = 0, curr = 0;
            unordered_map<int,int> mp;
            while (r < n) {
                mp[nums[r]]++;

                while (mp.size() > x) {
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) mp.erase(nums[l]);
                    l++;
                }

                cnt += (r - l + 1);
                r++;
            }
            return cnt;
        };
        return fn(k) - fn(k - 1);
    }
};
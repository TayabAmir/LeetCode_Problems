class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        function<int(int)> fn = [&](int x) -> int {
            int l = 0, r = 0;
            int cnt = 0, curr = 0;
            while(r < n){
                if(nums[r]&1) curr++;

                while(curr > x){
                    if(nums[l]&1) curr--;
                    l++;
                }

                cnt += (r-l+1);
                r++;
            }
            return cnt;
        };
        return fn(k) - fn(k-1);
    }
};
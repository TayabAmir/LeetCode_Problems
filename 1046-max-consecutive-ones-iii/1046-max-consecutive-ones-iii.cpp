class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, len = 0, n = nums.size();
        vector<int> v;
        int idx = 0;
        while(r < n){
            if(nums[r] == 0){
                v.push_back(r);
                if(k) k--;
                else l = v[idx++]+1;
            }
            cout << l << " " << r << endl;
            len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};
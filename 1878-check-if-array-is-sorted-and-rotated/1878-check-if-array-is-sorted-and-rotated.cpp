class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> helper = nums;
        sort(helper.begin(),helper.end());
        for(int i=1;i<=nums.size();i++){
            if(nums == helper)
                return true;
            reverse(nums.begin(),nums.end());
            reverse(nums.begin()+1,nums.end());
        }
        return false;
    }
};
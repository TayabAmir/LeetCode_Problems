class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        for(int ele : nums){
            if(lis.empty() || ele > lis.back()) lis.push_back(ele);
            else {
                auto it = lower_bound(lis.begin(), lis.end(), ele);
                *it = ele;
            }
        }
        return lis.size();
    }
};
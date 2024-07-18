class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(int ele : nums)
            ops += min(ele % 3, 3 - (ele % 3));
        return ops;
    }
};
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ops = 0;
        for(int ele : nums)
            if(ele % 3 != 0)
                ops++;
        return ops;
    }
};
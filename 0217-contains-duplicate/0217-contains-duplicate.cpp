class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int ele : nums)
        {
            if(m[ele] > 0)
                return true;
            m[ele]++;
        }
        return false;
    }
};
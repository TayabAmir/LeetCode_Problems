class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int ele : nums)
            m[ele]++;
        for(auto p : m)
            if(p.second == 1)
                return p.first;
        return -1;
    }
};
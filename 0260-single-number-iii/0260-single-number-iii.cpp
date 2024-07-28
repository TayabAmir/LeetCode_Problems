class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int ele : nums)
            m[ele]++;
        vector<int> res;
        for(auto p : m)
            if(p.second == 1)
                res.push_back(p.first);
        return res;
    }
};
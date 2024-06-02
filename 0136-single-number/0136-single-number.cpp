class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int ele : nums)
            m[ele]++;
        for(auto pair: m)
            if(pair.second==1)
                return pair.first;
        return -1;
    }
};
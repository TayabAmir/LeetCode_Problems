class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> res;
        for(int i : nums)
            freq[i]++;
        for(const auto pair : freq)
            if(pair.second == 2)
                res.push_back(pair.first);
        return res;
    }
};
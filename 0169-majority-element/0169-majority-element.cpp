class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> eles;
        for(int n : nums)
            eles[n]++;
        for(auto pair: eles)
            if(pair.second > floor(nums.size()/2))
                return pair.first;
        return -1;
    }
};
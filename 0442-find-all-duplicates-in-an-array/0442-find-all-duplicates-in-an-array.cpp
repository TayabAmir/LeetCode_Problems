class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> freq(nums.size() + 1, 0);
        for(int i : nums)
            freq[i]++;
        for(int i = 0,count = 0; i < freq.size();count++)
            if(freq[i] == 2)
                freq[i++] = count;
            else
                freq.erase(freq.begin() + i);
        return freq;
    }
};
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> freq(nums.size()+1, 0);
        for(int i=0 ; i < nums.size() ; i++)
            freq[nums[i]] = true;

        vector<int> miss;
        for(int i = 1; i < freq.size(); i++)
            if(!freq[i])
                miss.push_back(i);
        return miss;
    }
};
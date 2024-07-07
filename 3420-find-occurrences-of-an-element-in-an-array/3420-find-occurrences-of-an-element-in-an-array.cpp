class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& q, int x) {
        vector<int> helper;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == x) helper.push_back(i);
        for(int i = 0; i < q.size(); i++)
            q[i] = (q[i] <= helper.size()) ? helper[q[i]-1] : q[i] = -1;
        return q;
    }
};
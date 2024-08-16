class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& mF, vector<int>& mT) {
        set<int> s;
        for(int ele : nums) s.insert(ele);
        for(int i = 0; i < mF.size(); ++i) s.erase(s.find(mF[i])), s.insert(mT[i]);
        nums.clear();
        for(auto ele : s) nums.push_back(ele);
        return nums;
    }
};
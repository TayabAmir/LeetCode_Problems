class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]] = i;
        for(int i=0; i<operations.size(); i++){
            auto itr = m.find(operations[i][0]);
            if(itr != m.end()){
                nums[itr->second] = operations[i][1];
                m[operations[i][1]] = itr->second;
                m.erase(itr);
            }
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg,res;
        for(int ele : nums)
            (ele > 0) ? pos.push_back(ele) : neg.push_back(ele);
        for(int i=0;i<pos.size();i++){
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        return res;
    }
};
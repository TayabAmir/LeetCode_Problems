class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multimap<int,int,greater<int>> m;
        for(int i=0;i<nums.size();i++)
            m.insert(make_pair(nums[i],1));
        for(const auto& pair : m){
            --k;
            if(k == 0) return pair.first;
        }
        return -1;
    }
};
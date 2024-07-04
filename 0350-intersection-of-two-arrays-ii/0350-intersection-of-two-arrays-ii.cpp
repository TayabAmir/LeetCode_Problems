class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        for(int i=0;i<nums1.size();i++){
            auto itr = find(nums2.begin(),nums2.end(),nums1[i]);
            if(itr != nums2.end()){
                nums2.erase(itr);
                res.push_back(nums1[i]);
            }
        }
        return res;
    }
};
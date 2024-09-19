class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> arr;
        while(i < m && j < n)
            if(nums1[i] < nums2[j])
                arr.push_back(nums1[i++]);
            else arr.push_back(nums2[j++]);
        while(i < m) arr.push_back(nums1[i++]);
        while(j < n) arr.push_back(nums2[j++]);
        nums1 = arr;
    }
};
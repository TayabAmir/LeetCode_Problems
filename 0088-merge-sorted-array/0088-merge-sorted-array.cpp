class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = m + n - 1;
        while(m >= 1 and n >= 1){
            if(nums1[m-1] >= nums2[n-1])
                nums1[idx--] = nums1[--m];
            else 
                nums1[idx--] = nums2[--n];
        }
        while(m >= 1) nums1[idx--] = nums1[--m];
        while(n >= 1) nums1[idx--] = nums2[--n];
    }
};
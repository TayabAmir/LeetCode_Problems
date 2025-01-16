class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x = 0;
        for(int ele : nums2) 
            x ^= ele;
        
        if(nums2.size() % 2 == 0){
            if(nums1.size() % 2 == 0) return 0;
            return x;
        } else {
            int ans = 0;
            for(int ele : nums1){
                ans ^= (x ^ ele);
            }
            return ans;
        }
        // return x;
    }
};
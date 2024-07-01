class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
        int even = 0,odd = 1;
        for(int ele : nums){
            if(ele > 0){ 
                res[even] = ele;
                 even += 2;
            } else{
                res[odd] = ele;
                odd += 2;
            }
        }
        return res;
    }
};
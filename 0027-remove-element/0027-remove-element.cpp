class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), j = n - 1;
        int k = count(nums.begin(), nums.end(), val);

        for(int i = 0; i < nums.size() - k; i++){
            if(nums[i] == val){
                while(nums[j] == val) j--;
                swap(nums[i], nums[j]);
            }
        }
        return nums.size() - k;
    }
};
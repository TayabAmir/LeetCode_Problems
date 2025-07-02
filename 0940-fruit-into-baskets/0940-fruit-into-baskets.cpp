class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        int len = 0;
        unordered_map<int,int> freq;
        while(r < n){
            freq[nums[r]]++;
            if(freq.size() > 2){
                freq[nums[l]]--;
                if(freq[nums[l]] == 0) freq.erase(nums[l]);
                l++;
            } 

            if(freq.size() <= 2)
                len = max(len, r-l+1);
            r++;
        }
        return len;
    }
};
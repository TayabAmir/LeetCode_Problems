class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minN = 1001,maxN = 0;
        for(int ele : nums){
            minN = min(ele,minN);
            maxN = max(ele,maxN);
        }
        return gcd(minN,maxN);
    }
};
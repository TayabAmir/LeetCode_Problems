class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xorSum1 = 0,xorSum2=0;
        for(int ele : arr1)
            xorSum1 ^= ele;
        for(int ele : arr2)
            xorSum2 ^= ele;
        return xorSum1 & xorSum2;
    }
};
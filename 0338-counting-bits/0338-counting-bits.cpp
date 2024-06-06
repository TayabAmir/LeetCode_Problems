class Solution {
public:
    int hammingWeight(int n) {
        int no_of_Ones = 0;
        while(n)
        {
            no_of_Ones += (n & 1);
            n >>= 1;
        }
        return no_of_Ones;
    }
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0;i<=n;i++)
            result.push_back(hammingWeight(i));
        return result;
    }
};
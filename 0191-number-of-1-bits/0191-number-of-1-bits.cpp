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
};
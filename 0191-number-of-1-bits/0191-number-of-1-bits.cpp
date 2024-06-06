class Solution {
public:
    int hammingWeight(int n) {
        int no_of_Ones = 0;
        while(n)
        {
            if(n & 1) no_of_Ones++;
            n >>= 1;
        }
        return no_of_Ones;
    }
};
class Solution {
public:
    vector<long long> sumOfThree(long long n) {
        vector<long long> v;
        if(n % 3 == 0) v = {n/3 - 1, n/3 ,n/3 + 1};
        return v;
    }
};
class Solution {
public:
    long long minimumSteps(string s) {
        long long steps = 0;
        for(int i = s.length()-1, count = 0; i >= 0; i--)
            (s[i] == '0') ? count++ : steps += count;
        return steps;
    }
};
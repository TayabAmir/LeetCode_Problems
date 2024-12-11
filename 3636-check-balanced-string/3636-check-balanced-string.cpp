class Solution {
public:
    bool isBalanced(string num) {
        int sum = 0;
        for(int i = 0; i < num.length(); i+=2) sum += (num[i]-'0');
        for(int i = 1; i < num.length(); i+=2) sum -= (num[i]-'0');
        return sum == 0;
    }
};
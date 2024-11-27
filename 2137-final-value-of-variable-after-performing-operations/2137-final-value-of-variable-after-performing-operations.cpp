class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int x = 0;
        for(string s : op) s[1] == '+' ? x++ : x--;
        return x; 
    }
};
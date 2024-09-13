class Solution {
public:
    vector<string> ans;
    void solve(string s, int openBracket, int closeBracket, int n){
        if(openBracket == 0 && closeBracket == 0){
            ans.push_back(s);
            return;
        }
        if(openBracket != 0)
            solve(s+'(', openBracket-1, closeBracket, n);
        if(closeBracket != 0 && closeBracket > openBracket)
            solve(s+')', openBracket, closeBracket-1, n);
    }
    vector<string> generateParenthesis(int n) {
        solve("", n, n, n);
        return ans;
    }
};
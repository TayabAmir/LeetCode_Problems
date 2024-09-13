class Solution {
public:
    void solve(vector<string> &ans,string s, int openBracket, int closeBracket){
        if(openBracket == 0 && closeBracket == 0){
            ans.push_back(s);
            return;
        }
        if(openBracket != 0)
            solve(ans, s+'(', openBracket-1, closeBracket);
        if(closeBracket != 0 && closeBracket > openBracket)
            solve(ans, s+')', openBracket, closeBracket-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", n, n);
        return ans;
    }
};
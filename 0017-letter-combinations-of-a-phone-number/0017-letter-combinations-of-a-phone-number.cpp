class Solution {
public:
    vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;

    void f(string digits, int i,string s, vector<string>& res){
        if(i == digits.length()){
            res.push_back(s);
            return;
        }
        int digit = digits[i] - '0';
        for(int idx = 0; idx < mp[digit].size();idx++)
            f(digits, i+1, s + mp[digit][idx], res);
        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits != "")
            f(digits,0,"",res);
        return res;
    }
};
class Solution {
public:
    bool isSame(string s){
        return s[0] == s[1] && s[1] == s[2];
    }
    string largestGoodInteger(string s) {
        string maxi= "";
        for(int i = 0; i < s.size() - 2; i++){
            if(isSame(s.substr(i, 3))){
                maxi = max(maxi, s.substr(i, 3));
            }
        }
        return maxi;
    }
};
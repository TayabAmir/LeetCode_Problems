class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(int i=0;i<s.length();i++)
            if(isalpha(s[i]) || (s[i]>=48 && s[i]<=57))
                res += tolower(s[i]);
        return Palin(res);
    }
    bool Palin(string s)
    {
        if(s.length()==1)
            return true;
        for(int i=0,j=s.length()-1;i<j;)
            if(s[i++]!=s[j--])
                return false;
        return true;
    }
};
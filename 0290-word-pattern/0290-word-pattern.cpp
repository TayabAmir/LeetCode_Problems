class Solution {
public:
    string getString(int& i,string s)
    {
        string res = "";
        while(s[i] != ' ' && i < s.length()){
            res += s[i];
            i++;
        }
        return res;
    }
    bool checkString(unordered_map<char,string> m,string s,char c)
    {
        for (const auto& pair : m) {
            if (pair.second == s && pair.first != c) {
                return false;
            }
        }
        return true;
    }
    bool wordPattern(string pattern, string s) {
         unordered_map<char,string> m;
         int j=0;
         for(int i=0;i<pattern.length();i++,j++)
         {
            string t = getString(j,s);
            if(t == "") return false;
            if(m.find(pattern[i]) == m.end())
                if(checkString(m,t,pattern[i]))
                    m[pattern[i]] = t;
                else
                    return false;
            else if(m[pattern[i]] != t)
                return false;
         }
         if(j<s.length()) return false;
         return true;
    }
};
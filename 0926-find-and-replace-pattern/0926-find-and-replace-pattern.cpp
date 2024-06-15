class Solution {
public:
    bool Isomorphs(string s,string t)
    {
        map<char,char> iso;
        for(int i=0;i<s.length();i++)
            if(iso.find(s[i])==iso.end())
                iso[s[i]] = t[i];
            else if((iso[s[i]] != t[i]))
                return false;
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i=0;i<words.size();i++){
            if(Isomorphs(pattern,words[i]) && Isomorphs(words[i],pattern))
                res.push_back(words[i]);
        }
        return res;
    }
};
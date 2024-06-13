class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,bool> m;
        for(int i=0;i<s.length();i++)
            if(m.find(s[i]) != m.end())
                return s[i];
            else
                m[s[i]] = true;
        return 'A';
    }
};
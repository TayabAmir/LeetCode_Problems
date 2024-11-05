class Solution {
public:
    string makeFancyString(string s) {
        string t = "";
        for(int i = 0; i < s.length();){
            char c = s[i];
            int count = 0;
            while(i < s.length() && c == s[i]) count++, i++;
            t += c;
            if(count > 1) t += c;
        }
        return t;
    }
};
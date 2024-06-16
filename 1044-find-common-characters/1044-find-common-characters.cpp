class Solution {
public:
    bool Contains(vector<string>& words,char c){
        for(int i = 1; i < words.size(); i++) {
            bool found = false;
            for(int j = 0; j < words[i].length(); j++) {
                if(words[i][j] == c) {
                    words[i][j] = 'A';
                    found = true;
                    break;
                }
            }
            if(!found) {
                return false;
            }
        }
        return true;
    }
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        string s = words[0];
        for(int i=0;i<s.length();i++)
            if(Contains(words,s[i])){
                res.push_back(string(1, s[i]));
            }
        return res;
    }
};
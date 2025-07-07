class Solution {
public:
    bool check(string s, vector<int> f){
        for(char c : s) f[c-'a']--;
        return count(f.begin(), f.end(), 0) == 26;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> fre(26, 0);
        for(char c : s1) fre[c-'a']++;
        int n = s1.length(), m = s2.length();
        
        for(int i = 0; i < m - n + 1; i++){
            if(check(s2.substr(i, n), fre)) return true;
        }
        return false;
    }
};
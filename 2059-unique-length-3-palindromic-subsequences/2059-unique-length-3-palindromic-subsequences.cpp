class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> arrMin(26,-1) ;
        vector<int> arrMax(26,-1) ;
        for(int i = 0; i < s.length(); i++){
            if(arrMin[s[i]-'a'] == -1) arrMin[s[i]-'a'] = i;
        }
        for(int i = s.length()-1; i >= 0; i--){
            if(arrMax[s[i]-'a'] == -1) arrMax[s[i]-'a'] = i;
        }
        int count = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(arrMin[c-'a'] == -1 || arrMax[c-'a'] == -1 || arrMin[c-'a'] == arrMax[c-'a']) continue;
            set<char> st;
            for(int i = arrMin[c-'a']+1; i < arrMax[c-'a']; i++){
                st.insert(s[i]);
            }
            count += st.size();
        }
        return count;
    }
};
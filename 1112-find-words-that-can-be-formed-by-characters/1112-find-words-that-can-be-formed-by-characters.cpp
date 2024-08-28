class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int arr[26] = {0}, ans = 0;
        for(char c : chars) arr[c-'a']++;
        for(string s : words){
            int arr2[26] = {0};
            bool b = true;
            for(char c : s) arr2[c-'a']++;
            for(char c : s)
                if(arr[c-'a'] < arr2[c-'a']) b = false;
            if(b) ans += s.length();
        }
        return ans;
    }
};
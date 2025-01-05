class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> freq(s.length(), 0);
        for (auto sh : shifts) {
            if(sh[2] == 0){
                freq[sh[0]]--;
                if(sh[1]+1 < s.length())
                    freq[sh[1]+1]++;
            }
            else {
    	        freq[sh[0]]++;
                if(sh[1]+1<s.length())
                    freq[sh[1]+1]--;
            } 
        }
        for(int i = 1; i < s.length(); i++){
            freq[i] += freq[i-1];
        }
        for (int i = 0; i < s.length(); i++) {
            freq[i] %= 26;
            if(freq[i] < 0) freq[i] += 26;
            s[i] = 'a' + (s[i]- 'a' + freq[i]) % 26;
        }
        return s;
    }
};
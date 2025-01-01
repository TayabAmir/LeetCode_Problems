class Solution {
public:
    int maxScore(string s) {
        int totalZeros = 0, totalOnes = 0;
        for(char c : s) c == '1' ? totalOnes++ : totalZeros++;

        int score = 0, zeros = 0, ones = 0;
        for(int i = 0; i < s.length(); i++){
            s[i] == '1' ? ones++ : zeros++;
            score = max(score, zeros + (totalOnes-ones));
        }
        return score;
    }
};
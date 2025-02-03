class Solution {
public:
    char getHashedChar(string s, int &i, int k){
        int sum = 0;
        while(i < k)
            sum = sum + (s[i] - 97),i++;
        return (sum % 26) + 97;
    }
    string stringHash(string s, int k) {
        string result = "";
        int i = 0;
        while(i < s.length())
            result += getHashedChar(s, i, k+i);
        return result;
    }
};
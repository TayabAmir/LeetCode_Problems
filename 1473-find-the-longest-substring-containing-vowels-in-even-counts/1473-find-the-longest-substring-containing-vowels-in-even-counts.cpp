class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> vowels = { {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4} };
        unordered_map<int, int> bitmap;
        bitmap[0] = -1;
        int maxLen = 0, curr = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (vowels.find(ch) != vowels.end()) {
                curr ^= (1 << vowels[ch]);
            }
            if (bitmap.find(curr) == bitmap.end()) {
                bitmap[curr] = i;
            } else {
                maxLen = max(maxLen, i - bitmap[curr]);
            }
        }
        return maxLen;
    }
};
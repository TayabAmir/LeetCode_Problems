class Solution {
public:
    int possibleStringCount(string word) {
        int strings = 0, i = 0;
        while(i < word.length()){
            int curr = word[i];
            while(i < word.length() && curr == word[i])
                strings++, i++;
            strings--;
        }
        return strings+1;

    }
};
class Solution {
public:
    int minimizedStringLength(string s) {
        set<char> dis;
        for(char ele : s)
            dis.insert(ele);
        return dis.size();
    }
};
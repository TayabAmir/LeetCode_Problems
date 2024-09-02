class Solution {
public:
    bool checkTwoChessboards(string& C1, string& C2) {
        return (C1[0]-'a'+ C1[1]-'0') % 2 == (C2[0]-'a'+ C2[1]-'0') % 2;
    }
};
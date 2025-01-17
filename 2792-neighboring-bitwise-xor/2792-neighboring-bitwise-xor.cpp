class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int x = 0;
        for(int ele : d)
            x ^= ele;
        return x == 0;
    }
};
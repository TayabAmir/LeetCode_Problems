class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> fre(501, 0);
        for(int ele : arr) fre[ele]++;
        for(int i = 500; i >= 1; i--)
            if(i == fre[i])
                return i;
        return -1;
    }
};
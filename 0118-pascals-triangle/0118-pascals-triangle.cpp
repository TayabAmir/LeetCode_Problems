class Solution {
public:
    int C(int n, int r) {
        int result = 1;
        for (int i = 1; i <= r; ++i) {
            result *= (n - i + 1);
            result /= i;
        }
        return result;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            vector<int> temp;
            for(int j=0;j<=i;j++)
                temp.push_back(C(i,j)); 
            pascal.push_back(temp);
        }
        return pascal;
    }
};
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = INT_MIN,rowNo = -1;
        for(int i=0,ones = 0;i< mat.size();i++,ones=0)
        {
            for(int j=0;j < mat[i].size();j++)
            {
                if(mat[i][j]==1)
                    ones++;
            }
            if(ones == maxOnes)
                rowNo = min(rowNo,i);
            else if(ones>maxOnes)
            {
                maxOnes = ones;
                rowNo = i;
            }
        }
        return {rowNo,maxOnes};
    }
};
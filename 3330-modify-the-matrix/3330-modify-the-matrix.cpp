class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> answer = matrix;
        int m = answer.size(),n = answer[0].size();
        for(int cols = 0,maxNo = -2;cols < n ; cols++,maxNo = -2)
        {
            for(int rows = 0;rows < m; rows++)
                maxNo = max(maxNo,answer[rows][cols]);
            for(int rows = 0;rows < m; rows++)
                if(answer[rows][cols] == -1)
                    answer[rows][cols] = maxNo;
        }
        return answer;
    }
};
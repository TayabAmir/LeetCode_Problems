class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(const auto &ele : rows){
            cout << ele;
            for(int i = 0; i < matrix[ele].size(); i++){
                matrix[ele][i] = 0;
            }
        }

        for(const auto &ele : cols){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][ele] = 0;
            }
        }
    }
};
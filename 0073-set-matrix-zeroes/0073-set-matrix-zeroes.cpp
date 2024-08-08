class Solution {
public:
    void setZeros(vector<vector<int>>& matrix,int row,int col){
        for(int i=0;i<matrix.size();i++)
            matrix[i][col] = 0;
        for(int i=0; i<matrix[0].size();i++)
            matrix[row][i] =0;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){
                    v.push_back(make_pair(i,j));
                }
            }
        }
        for(auto p : v){
            setZeros(matrix,p.first,p.second);
        }
    }
};
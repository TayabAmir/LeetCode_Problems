class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c != mat.size()*mat[0].size()) return mat;
        vector<vector<int>> s;
        vector<int> d;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                d.push_back(mat[i][j]);
                if(d.size() == c){
                    s.push_back(d);
                    d.clear();
                }
            }
        }

        return s;
    }
};
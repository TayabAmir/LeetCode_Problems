class Solution {
public:
    double getDiagonalLength(int x, int y){
        return sqrt(x*x + y*y);
    }
    int areaOfMaxDiagonal(vector<vector<int>>& d) {
        double dL = getDiagonalLength(d[0][0],d[0][1]);
        int maxIndex = 0;
        for(int i = 1; i < d.size(); i++){
            double l = getDiagonalLength(d[i][0],d[i][1]);
            if(dL < l){
                dL = l, maxIndex = i;
            }
        }
        int area = d[maxIndex][0] * d[maxIndex][1];
        for(auto row : d){
            if(getDiagonalLength(row[0],row[1]) == dL){
                area = max(area, row[0]*row[1]);
            }
        }
        return area;
    }
};
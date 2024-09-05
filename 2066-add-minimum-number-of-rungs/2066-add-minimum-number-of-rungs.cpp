class Solution {
public:
    int addRungs(vector<int>& r, int d) {
        int height = 0, rungs = 0;

        for(int i = 0; i < r.size(); ++i){
            height += d;
            if(height < r[i])
                rungs += ceil((double)(r[i] - height) / d);  
            height = r[i];
        }
        return rungs;
    }
};
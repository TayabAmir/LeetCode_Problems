class Solution {
public:
    int hIndex(vector<int>& c) {
        int o = 0;
        for(int i = 0; i <= c.size(); i++){
            int co = 0;
            for(int j = 0; j < c.size(); j++)
                if(c[j] >= i) co++;
            if(i == min(co,i) && i > o) o = i;
        }
        return o;
    }
};
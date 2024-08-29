class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> v(k);
        for(int i = 0; i < mat.size(); i++){
            int c = count(mat[i].begin(), mat[i].end(), 1);
            pq.push(make_pair(c, i));
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
            v[--k] = pq.top().second;
            pq.pop();
        }
        return v;
    }
};
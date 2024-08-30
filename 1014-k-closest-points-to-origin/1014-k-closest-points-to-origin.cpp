class Solution {
public:
    double calculateDistance(int x, int y){
        return sqrt((x*x)+(y*y));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        
        for(auto v : points){
            pq.push(make_pair(calculateDistance(v[0], v[1]), v));
            if(pq.size() > k) pq.pop();
        }
        points.resize(k);
        while(!pq.empty()){
            points[--k] = pq.top().second;
            pq.pop();
        }
        return points;
    }
};
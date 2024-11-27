class Solution {
public:
    int dijkstra(int n, vector<vector<int>> adj){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> distance(n, INT_MAX);
        distance[0] = 0;
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            int dist = p.first, node = p.second;

            for(int neighbor : adj[node]){
                if(dist + 1 < distance[neighbor]){
                    distance[neighbor] = dist+1;
                    pq.push({dist+1, neighbor});
                }
            }
        }
        return distance[n-1];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
            if(i != n -1)
                adj[i].push_back(i+1);

        // for(int i = 0; i < n; i++){
        //     cout << i << "-->";
        //     for(int j : adj[i]){
        //         cout << j << " ";
        //     }cout << endl;
        // }
        vector<int> distances;
        for(auto q : queries){
            adj[q[0]].push_back(q[1]);
            distances.push_back(dijkstra(n, adj));
        }
        return distances;
    }
};
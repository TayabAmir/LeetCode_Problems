class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, vector<int>> usersFollowed;
    int t = 1;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({t, tweetId});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        auto comp = [&](const pair<int,int> &a, const pair<int,int> &b) {
            return a.first < b.first;
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);

        for(auto post : tweets[userId]){
            pq.push(post);
        }
        
        for(int follower : usersFollowed[userId]){
            for(auto post : tweets[follower]){
                pq.push(post);
            }
        }
        set<int> seen;
        vector<int> out;

        while (!pq.empty() && out.size() < 10) {
            int val = pq.top().second;
            pq.pop();

            if (seen.count(val) == 0) {
                seen.insert(val);
                out.push_back(val);
            }
        }
        return out;
    }

    void follow(int followerId, int followeeId) {
        usersFollowed[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) { 
        auto& followed = usersFollowed[followerId];
        auto it2 = find(followed.begin(), followed.end(), followeeId);
        if (it2 != followed.end()) {
            followed.erase(it2);
        }
    }

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
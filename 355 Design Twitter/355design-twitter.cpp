class Twitter {
public:
    unordered_map<int,set<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
    long long time;
    Twitter() {
        time=0;   
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});        
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto tweet:tweets[userId]){
            pq.push(tweet);
        }

        for(auto user:followers[userId]){
            for(auto tweet:tweets[user]){
                pq.push(tweet);
            }
        }
        vector<int> res;
        int k=10;
        while(!pq.empty() && k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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
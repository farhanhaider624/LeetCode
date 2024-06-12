class Twitter {
public:
    vector<vector<int>> post;
    unordered_map<int, set<int>> mp;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        int cnt=10, i=post.size()-1;
        while(cnt>=1 && i>=0){
            if(userId==post[i][0]){
                newsFeed.push_back(post[i][1]);
                cnt--;
            }
            else if(mp[userId].find(post[i][0])!=mp[userId].end()){
                newsFeed.push_back(post[i][1]);
                cnt--;
            }
            i--;
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
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
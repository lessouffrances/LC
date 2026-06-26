class Twitter 
{
    public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) 
    {
        idToPosts[userId].push_back(tweetId);
        globalTweetStorage.push_back( {userId, tweetId} );
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        // top 10
        // iterate through the global LL
        // only look at those tweets by himself or people he followed
        vector<int> res;
        for (auto iter = globalTweetStorage.rbegin(); iter != globalTweetStorage.rend(); iter++) {
            if (res.size() == 10) break;
            int authorId = iter->first;
            int tweetId = iter->second;
            if (authorId == userId || adjList[userId].count(authorId)) {
                res.push_back(tweetId);
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) 
    {
        adjList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        adjList[followerId].erase(followeeId);
    }

    private:
    unordered_map<int, unordered_set<int>> adjList; // store the user: list of users that he follows
    unordered_map<int, vector<int>> idToPosts; // store the user: list of tweets that he posted
    // we want this list of posts to be ordered by ts
    list<pair<int, int>> globalTweetStorage;  // {userId, tweetId}
};    
class Twitter 
{
    public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) 
    {
        idToPosts[userId].push_back( {ts++, tweetId} );
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        // collect all tweets from himself and his followees
        // maxHeap: based on ts, larger ts number on top
        priority_queue<pair<int, int>> maxHeap; 
        // iterate thru followees
        for (auto& followee : adjList[userId]) {
            for (auto& [ts, tweetId] : idToPosts[followee]) {
                maxHeap.push( {ts, tweetId} );
            } 
        }

        // iterate thru his own posts
        for (auto& [ts, tweetId] : idToPosts[userId]) {
            maxHeap.push( {ts, tweetId} );
        }

        vector<int> res;
        while (!maxHeap.empty() && res.size() < 10) {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
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
    int ts = 0; // global time
    unordered_map<int, unordered_set<int>> adjList; // store the user: list of users that he follows
    unordered_map<int, vector<pair<int, int>>> idToPosts; 
    // userId:  {...  {ts, tweetId} ... }
};    
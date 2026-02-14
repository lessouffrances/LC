class Leaderboard 
{
    public:
    Leaderboard() {}
    void addScore(int playerId, int score) 
    {
        if (leaderboard.count(playerId)) {
            leaderboard[playerId] += score;
        } else {
            leaderboard[playerId] = score;
        }
    }
    int top(int K) 
    {
        priority_queue<int> maxHeap;
        for (auto& [_, score] : leaderboard) {
            maxHeap.push(score);
        }

        int res = 0;
        while (K > 0) {
            res += maxHeap.top();
            maxHeap.pop();
            K--;
        }
        return res;
    }
    void reset(int playerId) 
    {
        leaderboard.erase(playerId);
    }
    private:
    unordered_map<int, int> leaderboard;
};
    
    
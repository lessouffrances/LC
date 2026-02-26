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
        priority_queue<pair<int, int>> pq; // max score on top
        for (auto& [id, score] : leaderboard) {
            pq.push( {score, id} );
        }

        int k = K;
        int res = 0;
        while (k > 0 && !pq.empty()) {
            res += pq.top().first;
            pq.pop();
            k--;
        }
        return res;
    }

    void reset(int playerId) 
    {
        leaderboard.erase(playerId);
    }
    private:
    unordered_map<int, int> leaderboard; // id : score
};
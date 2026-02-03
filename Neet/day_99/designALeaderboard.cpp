





class Leaderboard 
{
    public:
    Leaderboard() {}

    void addScore(int playerId, int score) 
    {
        if (playerToScore.count(playerId)) {
            playerToScore[playerId] += score;
        } else {
            playerToScore[playerId] = score;
        }
    }

    int top(int K) 
    {
        int scoreSum = 0;
        priority_queue<int> pq;
        for (auto& [id, score] : playerToScore) {
            pq.push(score);
        }
        for (int i=0; i<K; i++) {
            scoreSum += pq.top();
            pq.pop();
        }
        return scoreSum;
    }
    
    void reset(int playerId) 
    {
        if (playerToScore.count(playerId)) {
            playerToScore.erase(playerId);
        }
    }

    private:
    unordered_map<int, int> playerToScore;

};
    
    
class Leaderboard 
{
    public:
    Leaderboard() {}

    void addScore(int playerId, int score) 
    {
        if (board.count(playerId)) {
            board[playerId] += score;
        } else {
            board[playerId] = score;
        }
    }
    
    int top(int K) 
    {
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq; // minHeap
        int currSum = 0;
        for (auto& [_, score] : board) {
            pq.push(score);
            currSum += score;
            if (pq.size() > K) {
                currSum -= pq.top();
                pq.pop();
            }
        }
        return currSum;
    }
    
    void reset(int playerId) 
    {
        if (board.count(playerId)) {
            board[playerId] = 0;
        } 
    }
    private:
    unordered_map<int, int> board;
};
  
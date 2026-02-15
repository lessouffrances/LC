class Solution 
{
    public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        if (players.empty() || trainers.empty()) return 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int m = players.size();
        int n = trainers.size();

        int i = 0, j = 0;
        int numOfMatch = 0;
        while (i < m && j < n) {
            if (players[i] <= trainers[j]) {
                i++;
                numOfMatch++;
            }
            j++;
        }
        return numOfMatch;
    }
};
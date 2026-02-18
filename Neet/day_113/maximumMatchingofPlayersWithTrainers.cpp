class Solution 
{
    public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        if (players.empty()) return 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = players.size()-1;
        int j = trainers.size()-1;

        int numOfMatch = 0;
        while (i>=0 && j>=0) {
            if (trainers[j] >= players[i]) {
                j--;
                numOfMatch++;
            }
            i--;
        }
        return numOfMatch;
    }
};
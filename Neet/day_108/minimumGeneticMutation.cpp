class Solution 
{
    public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        unordered_set<string> wordSet(bank.begin(), bank.end());

        if (!wordSet.count(endGene)) return -1;
        if (startGene == endGene) return 0;

        queue<string> q;
        q.push(startGene);
        set<string> visited;
        visited.insert(startGene);

        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currState = q.front();
                q.pop();

                if (currState == endGene) return moves; 

                for (int idx=0; idx<currState.length(); idx++) {
                    char originalChar = currState[idx];

                    for (char ch='A'; ch<='Z'; ch++) {
                        if (ch == originalChar) continue;

                        currState[idx] = ch;
                        if (!wordSet.count(currState) || visited.count(currState)) {
                            currState[idx] = originalChar;
                            continue;
                        }
                        q.push(currState);
                        visited.insert(currState);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
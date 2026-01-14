class Solution {
    public:
    vector<int> DELTAS = {-1, 1};
    int openLock(vector<string>& deadends, string target) 
    {
        set<string> deadendSet(deadends.begin(), deadends.end());

        if (deadendSet.count("0000") || deadendSet.count(target)) return -1;
        if (target == "0000") return 0;

        queue<pair<string, int>> q;
        set<string> visited;

        q.push({"0000", 0});
        visited.insert("0000");

        while (!q.empty()) {
            auto [currState, moves] = q.front();
            q.pop();

            for (int i=0; i<4; i++) {
                for (auto& DELTA : DELTAS) {
                    string nextState = currState;
                    int digit = currState[i]-'0';
                    int newDigit = (digit + DELTA + 10) % 10;
                    nextState[i] = newDigit + '0';

                    if (nextState == target) return moves + 1;

                    if (visited.count(nextState) || deadendSet.count(nextState)) continue;
                    visited.insert(nextState);
                    q.push( {nextState, moves+1} );
                }
            }
        }
        return -1;
    }
};
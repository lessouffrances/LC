class Solution 
{
    public:
    vector<int> DELTAS = {-1, 1};
    int openLock(vector<string>& deadends, string target) 
    {
        if (target == "0000") return 0;
        unordered_set<string> deadendsSet(deadends.begin(), deadends.end());
        if (deadendsSet.count("0000") || deadendsSet.count(target)) return -1;

        queue<string> q;
        q.push("0000");
        set<string> visited;
        visited.insert("0000");

        
        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            moves++;

            for (int i=0; i<size; i++) {
                auto code = q.front();
                q.pop();

                for (int idx=0; idx<4; idx++) {
                    for (auto& DELTA : DELTAS) {
                        string newCode = code;
                        int digit = newCode[idx]-'0';
                        int newDigit = (digit + DELTA + 10) % 10; 
                        newCode[idx] = newDigit + '0';

                        if (newCode == target) return moves;
                        if (visited.count(newCode) || deadendsSet.count(newCode)) continue;
                        visited.insert(newCode);
                        q.push(newCode);
                    }
                }
            }
        }
        return -1;
    }
};
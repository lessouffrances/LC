class Solution 
{
    public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        // return -1 if it is impossible
        if (deadendSet.count("0000") || deadendSet.count(target)) return -1;
        
        vector<int> DIRS = {-1, 1};
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
    
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currCode = q.front();
                q.pop();

                if (currCode == target) return steps;

                // change each pos of the currCode and turn it into each other digit from 0-9
                for (int idx=0; idx<4; idx++) {
                    char originalDigit = currCode[idx];
                    for (auto& DIR : DIRS) {
                        char newDigit = '0' + ((originalDigit - '0') + DIR + 10) % 10;
                        currCode[idx] = newDigit;
                        if (deadendSet.count(currCode) || visited.count(currCode)) continue;
                        q.push(currCode);
                        visited.insert(currCode); 
                    }
                    currCode[idx] = originalDigit; // backtrack
                }
            }
            steps++;
        }
        return -1;
    }
};
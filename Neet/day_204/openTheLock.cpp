class Solution 
{
    public:
    int openLock(vector<string>& deadends, string target) 
    {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        if (deadendSet.count(target) || deadendSet.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");

        vector<int> DIRS = {-1, 1};
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currStatus = q.front();
                q.pop();

                if (currStatus == target) return steps;

                for (int j=0; j<4; j++) {
                    char originalChar = currStatus[j];
                    for (auto& DIR : DIRS) {
                        currStatus[j] = '0' + ((originalChar - '0') + DIR + 10) % 10;
                        if (deadendSet.count(currStatus) || visited.count(currStatus)) continue;
                        q.push(currStatus);
                        visited.insert(currStatus);
                    }
                    currStatus[j] = originalChar;
                }
            }
            steps++;
        }
        return -1;
    }
};
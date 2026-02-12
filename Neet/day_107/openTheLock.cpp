


class Solution 
{
    public:
    int openLock(vector<string>& deadends, string target) 
    {
        if (target == "0000") return 0;
        vector<int> DIRS = {-1, 1};

        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        if (deadendSet.count(target) || deadendSet.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currState = q.front();
                q.pop();

                if (currState == target) return steps;

                for (int j=0; j<4; j++) {
                    int originalDigit = currState[j] - '0';
                    for (int DIR : DIRS) {
                        int newDigit = (originalDigit + DIR + 10) % 10;
                        currState[j] = newDigit + '0';

                        if (deadendSet.count(currState) || visited.count(currState)) {
                            currState[j] = originalDigit + '0';  
                            continue;
                        }
                        q.push(currState);
                        visited.insert(currState);

                        currState[j] = originalDigit + '0';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};









class Solution 
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();

            steps++;
            for (int i=0; i<size; i++) {
                auto currState = q.front();
                q.pop();

                if (currState == endWord) return steps;

                for (int j=0; j<currState.size(); j++) {
                    char originalCh = currState[j];

                    for (char ch='a'; ch<='z'; ch++) {
                        currState[j] = ch;
                        if (!wordSet.count(currState) || visited.count(currState)) {
                            currState[j] = originalCh; // backtrack
                            continue; 
                        }

                        q.push(currState);
                        visited.insert(currState);
                    }
                    currState[j] = originalCh;
                }
            }
        }
        return 0;
    }
};
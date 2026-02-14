class Solution 
{
    public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) 
    {
        if (dictionary.empty() || queries.empty()) return {};

        unordered_set<string> wordSet(dictionary.begin(), dictionary.end());

        vector<string> res;
        for (auto& query : queries) {
            if (bfs(query, wordSet)) {
                res.push_back(query);
            }
        }
        return res;
    }
    private:
    bool bfs(const string& query, unordered_set<string>& wordSet)
    {
        if (wordSet.count(query)) return true;

        queue<string> q;
        q.push(query);
        set<string> visited;
        visited.insert(query);

        int steps = 0;
        while (!q.empty() && steps < 2) {
            int size = q.size();
            steps++;

            for (int i=0; i<size; i++) {
                auto currState = q.front();
                q.pop();

                // if (wordSet.count(currState) && steps <= 2) return true;

                for (int idx=0; idx<currState.length(); idx++) {
                    char originalCh = currState[idx];
                    for (char ch='a'; ch<='z'; ch++) {
                        if (ch == originalCh) continue;
                        currState[idx] = ch;

                        if (wordSet.count(currState)) return true;
                        if (visited.count(currState)) {
                            currState[idx] = originalCh;
                            continue;
                        }

                        q.push(currState);
                        visited.insert(currState);
                        currState[idx] = originalCh;
                    }
                }
            }
        }
        return false;
    }
};
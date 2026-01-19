class Solution 
{
    public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        // convert the wordList into a set
        set<string> wordSet = set<string>(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};
        
        queue<vector<string>> q;
        q.push( {beginWord });
        set<string> visited;
        visited.insert(beginWord);

        vector<vector<string>> res;
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            set<string> levelVisited;

            for (int i=0; i<size; i++) {
                auto currPath = q.front();
                q.pop();
                string currStr = currPath.back();

                if (currStr == endWord) {
                    res.push_back(currPath);
                    found = true;
                    continue;
                }

                unordered_map<int, char> currStrHash = buildHash(currStr);
                for (auto& word : wordSet) {
                    if (visited.count(word)) continue;
                    unordered_map<int, char> wordHash = buildHash(word);
                    if (isAdjacent(currStrHash, wordHash)) {
                        levelVisited.insert(word);
                        currPath.push_back(word);
                        q.push(currPath);
                        currPath.pop_back();
                    }
                }
            }
            for (auto& word : levelVisited) {
                visited.insert(word);
            }
        }
        return res;
    }
    private:
    bool isAdjacent(unordered_map<int, char>& a, unordered_map<int, char>& b)
    {
        if (a.size() != b.size()) return false;
        int diffNum = 0;
        for (auto& [idx, ch] : a) {
            if (b[idx] != ch) {
                diffNum++;
            }
            if (diffNum > 1) return false;
        }
        return diffNum == 1;
    }
    unordered_map<int, char> buildHash(const string& s)
    {
        unordered_map<int, char> res;
        int i = 0;
        for (char ch : s) {
            res[i] = ch;
            i++;
        }
        return res;
    }
};
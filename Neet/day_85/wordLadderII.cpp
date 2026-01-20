class Solution 
{
    public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};

        unordered_set<string> currLevel;
        currLevel.insert(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);

        bool found = false;

        while (!currLevel.empty() && !found) {
            unordered_set<string> nextLevel;
            for (const string& word : currLevel) {
                string temp = word;

                // try changing each char in the word
                for (int idx=0; idx<word.length(); idx++) {
                    char originalChar = word[idx];

                    for (char ch='a'; ch<='z'; ch++) {
                        if (ch == originalChar) continue;
                        temp[idx] = ch;

                        if (wordSet.count(temp)) {
                            if (temp == endWord) found = true;

                            if (!visited.count(temp)) {
                                nextLevel.insert(temp);
                                parents[temp].push_back(word);
                            }
                        }
                    }
                    temp[idx] = originalChar;
                }
            }
            for (const string& word : nextLevel) {
                visited.insert(word);
            }
            currLevel = nextLevel;
        }

        if (!found) return {};

        vector<string> startPath = { endWord };
        dfs(endWord, beginWord, startPath);
        return res; 
    }
    private:
    vector<vector<string>> res;
    unordered_map<string, vector<string>> parents;
    void dfs(const string& word, const string& beginWord, vector<string>& path) 
    {
        if (word == beginWord) {
            res.push_back(vector<string>(path.rbegin(), path.rend()));
            return;
        }

        for (const auto& parent : parents[word]) {
            path.push_back(parent);
            dfs(parent, beginWord, path);
            path.pop_back();
        }
    }
};
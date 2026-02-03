class Solution 
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if (wordList.empty()) return 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord) || beginWord == endWord) return 0;

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> visited;
        visited.insert(beginWord);

        int levels = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currWord = q.front();
                q.pop();

                if (currWord == endWord) return levels;

                for (int idx=0; idx<currWord.length(); idx++) {
                    char originalChar = currWord[idx];
                    for (int ch='a'; ch<='z'; ch++) {
                        currWord[idx] = ch;
                        if (visited.count(currWord)) continue;
                        if (wordSet.count(currWord)) {
                            q.push(currWord);
                            visited.insert(currWord);
                        }
                    }
                    currWord[idx] = originalChar; 
                }
            }
            levels++;
        }
        return 0;
    }
};
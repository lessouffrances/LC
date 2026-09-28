


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

        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currWord = q.front(); q.pop();

                if (currWord == endWord) return steps;

                for (int idx=0; idx<currWord.length(); idx++) {
                    char original = currWord[idx];
                    for (char ch='a'; ch<='z'; ch++) {
                        currWord[idx] = ch;
                        if (visited.count(currWord) || !wordSet.count(currWord)) continue;
                        q.push(currWord);
                        visited.insert(currWord);
                    }
                    currWord[idx] = original;
                }
            }
            steps++;
        }
        return 0;
    }
};
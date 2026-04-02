




// Time: O(N * M), where N is the size of the list and M is the avg length of a string
// Space: O(N * M)
class Solution 
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if (beginWord == endWord) return 0;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            steps++;
            for (int i=0; i<size; i++) {
                auto currWord = q.front();
                q.pop();

                if (currWord == endWord) return steps;

                // toggle each pos 
                for (int j=0; j<currWord.length(); j++) {
                    char originalCh = currWord[j];
                    for (char ch='a'; ch<='z'; ch++) {
                        if (ch == currWord[j]) continue;
                        currWord[j] = ch;
                        if (!wordSet.count(currWord) || visited.count(currWord)) {
                            currWord[j] = originalCh;
                            continue;
                        }

                        q.push(currWord);
                        visited.insert(currWord);
                        currWord[j] = originalCh;
                    }
                }
            }
        }
        return 0;
    }
};
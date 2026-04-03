

// Time: O(N * M), where N is the # of the wordList, M is the avg size of the word
// Space: O(N)
class Solution 
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        if (beginWord == endWord) return 0;

        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            steps++;

            // for each word
            for (int i=0; i<size; i++) {
                auto currWord = q.front();
                q.pop();

                if (currWord == endWord) return steps;
                
                // for each pos in this word
                for (int j=0; j<currWord.length(); j++) {
                    // for each substitution
                    char originalChar = currWord[j];

                    for (char ch='a'; ch<='z'; ch++) {
                        if (ch == currWord[j]) continue;
                        // replace the char
                        currWord[j] = ch;
                        if (!wordSet.count(currWord)) {
                            currWord[j] = originalChar;
                            continue;
                        }
                        wordSet.erase(currWord); // mark visited
                        q.push(currWord);
                        currWord[j] = originalChar;
                    }
                }
            }
        }
        return 0;
    }
};
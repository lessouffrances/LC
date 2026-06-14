class Solution 
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        // ways to track visited
        // erase that word from the set
        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currStatus = q.front();
                q.pop();

                if (currStatus == endWord) return steps;
                for (int j=0; j<currStatus.length(); j++) {
                    char originalChar = currStatus[j];

                    for (char ch='a'; ch<='z'; ch++) {
                        if (ch == originalChar) continue;
                        currStatus[j] = ch;
                        if (!wordSet.count(currStatus)) continue;
                        q.push(currStatus);
                        wordSet.erase(currStatus); // visited
                    }
                    currStatus[j] = originalChar; // backtrack
                }
            }
            steps++;
        }
        return 0;
    }
};
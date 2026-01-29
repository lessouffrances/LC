class Solution 
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        sort(wordList.begin(), wordList.end());
        if (beginWord.length() == 0 || endWord.length() == 0 || wordList.empty()
            || !binary_search(wordList.begin(), wordList.end(), endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        set<string> visited;
        visited.insert(beginWord);

        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currStr = q.front();
                q.pop();

                if (currStr == endWord) return level;

                // change each idx to diff char
                for (int idx=0; idx<currStr.length(); idx++) {
                    char originalChar = currStr[idx];
                    for (char ch='a'; ch<='z'; ch++) {
                        if (ch == originalChar) continue;

                        currStr[idx] = ch;
                        if (binary_search(wordList.begin(), wordList.end(), currStr) && !visited.count(currStr)) {
                            q.push(currStr);
                            visited.insert(currStr);
                        }
                        currStr[idx] = originalChar; 
                    }
                }
            }
            level++;
        }
        return 0;
    }
};
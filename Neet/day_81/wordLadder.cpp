class Solution 
{
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        sort(wordList.begin(), wordList.end());
        if (beginWord.empty() || endWord.empty() || wordList.empty() 
            || !binary_search(wordList.begin(), wordList.end(), endWord)) {
            return 0;
        } 

        queue<string> q;
        q.push(beginWord);
        set<string> visited;
        visited.insert(beginWord);

        int l = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currStr = q.front();
                q.pop();

                if (currStr == endWord) {
                    return l;
                }

                for (int idx=0; idx<currStr.length(); idx++) {
                    char ch = currStr[idx];

                    for (char c='a'; c<='z'; c++) {
                        currStr[idx] = c;
                        if (binary_search(wordList.begin(), wordList.end(), currStr) && !visited.count(currStr)) {
                            q.push(currStr);
                            visited.insert(currStr);
                        }
                        currStr[idx] = ch;
                    }
                }
            }
            l++;
        }
        return 0;
    }
};

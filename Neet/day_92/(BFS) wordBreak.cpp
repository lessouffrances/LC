class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool>visited(s.length(), false);
        q.push(0);

        while (!q.empty()) {
            int start = q.front();
            q.pop();

            if (visited[start]) continue;
            visited[start] = true;

            for (int end=start+1; end <= s.length(); end++) {
                if (wordSet.count(s.substr(start, end-start))) {
                    if (end == s.length()) return true;
                    q.push(end);
                }
            }
        }
        return false;
    }
};
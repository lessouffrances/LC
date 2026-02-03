class Solution 
{
    public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> visited(s.length(), false);
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            auto startIdx = q.front();
            q.pop();

            if (startIdx == s.length()) return true;

            for (int endIdx=startIdx+1; endIdx<=s.length(); endIdx++) {
                if (wordSet.count(s.substr(startIdx, endIdx-startIdx))) {
                    if (visited[endIdx] == true) continue;
                    q.push(endIdx);
                    visited[endIdx] = true;
                }
            }
        }
        return false;
    }
};
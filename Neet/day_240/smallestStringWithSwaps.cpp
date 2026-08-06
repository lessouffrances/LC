class Solution 
{
    public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        buildGraph(pairs);
        for (int i=0; i<s.length(); i++) {
            if (visited.count(i)) continue;
            vector<int> conn;
            dfs(i, conn);

            vector<int> sortedIndices = conn;
            sort(sortedIndices.begin(), sortedIndices.end());

            string chars;
            for (int idx : conn) chars += s[idx];
            sort(chars.begin(), chars.end());

            for (int k=0; k<sortedIndices.size(); k++) {
                s[sortedIndices[k]] = chars[k];
            }
        }
        return s;
    }

    private:
    unordered_map<int, vector<int>> graph;
    set<int> visited;

    void dfs(int src, vector<int>& conn)
    {
        conn.push_back(src);
        visited.insert(src);
        for (auto& v : graph[src]) {
            if (visited.count(v)) continue;
            dfs(v, conn);
        }
    }

    void buildGraph(vector<vector<int>>& pairs)
    {
        if (pairs.empty()) return;
        for (auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
    }
};
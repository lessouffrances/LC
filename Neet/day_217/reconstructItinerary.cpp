class Solution 
{
    public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        buildSortedGraph(tickets);
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }

    private:
    vector<string> res;
    unordered_map<string, multiset<string>> graph;
    void dfs(string u)
    {
        while (!graph[u].empty()) {
            string next = *graph[u].begin();
            graph[u].erase(graph[u].begin());
            dfs(next);
        }
        res.push_back(u);
    }

    void buildSortedGraph(vector<vector<string>>& tickets)
    {
        for (auto& t : tickets) {
            graph[t[0]].insert(t[1]);
        }
    }
};
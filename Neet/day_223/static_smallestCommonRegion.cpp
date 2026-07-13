class Solution 
{
    public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) 
    {
        if (regions.empty()) return "";
        buildGraph(regions);
        // collect ancestors for region 1
        unordered_set<string> ancestors1;
        string curr = region1;
        while (true) 
        {
            ancestors1.insert(curr);
            if (!graph.count(curr)) break; // no more ancestor
            curr = graph[curr];
        }
        // walk up from region2 until hitting ancestor of region1
        curr = region2;
        while (!ancestors1.count(curr)) 
        {
            curr = graph[curr];
        }
        return curr;
    }

    private:
    // child: { parents }
    unordered_map<string, string> graph; 
    void buildGraph(vector<vector<string>>& regions) 
    {
        for (auto& cluster : regions) {
            auto& par = cluster[0];
            for (int i=1; i<cluster.size(); i++) {
                graph[cluster[i]] = par;
            }
        }
    }
};
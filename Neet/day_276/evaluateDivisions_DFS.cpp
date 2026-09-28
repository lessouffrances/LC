class Solution 
{
    public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
        vector<double>& values, vector<vector<string>>& queries) 
    {
        if (equations.empty() || values.empty()) return {};
        buildGraph(equations, values);

        function<void(const string&, const string&, unordered_set<string>&, double)> dfs = 
            [&](const string& src, const string& dest, unordered_set<string>& visited, double currProduct) -> void {
            if (src == dest) { result = currProduct; return; }
            visited.insert(src);

            for (auto& [v, weight] : graph[src]) {
                if (visited.count(v)) continue;
                dfs(v, dest, visited, currProduct * weight);
            }
        };

        vector<double> res;
        for (auto& query : queries) {
            string u = query[0];
            string v = query[1];
            string id = u + "->" + v;

            if (cache.count(id)) {
                res.push_back(cache[id]);
                continue;
            }
            if (!graph.count(u) || !graph.count(v)) {
                res.push_back(-1.0);
                continue;
            }

            result = -1.0;
            unordered_set<string> visited;
            dfs(u, v, visited, 1.0);

            cache[id] = result;
            res.push_back(result);
        }
        return res;
    }

    private:
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_map<string, double> cache;
    double result;

    void buildGraph(vector<vector<string>>& equations, vector<double>& values)
    {
        int n = equations.size();

        for (int i=0; i<n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double weight = values[i];
            graph[u].push_back( {v, weight} );
            graph[v].push_back( {u, 1 / weight} );
        }
    }
};
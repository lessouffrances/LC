class Solution 
{
    public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        if (equations.empty() || values.empty() || queries.empty()) return {};

        buildGraph(equations, values);

        int n = queries.size();
        vector<double> res;

        for (int i=0; i<n; i++) {
            string u = queries[i][0];
            string v = queries[i][1];

            if (!graph.count(u) || !graph.count(v)) {
                res.push_back(-1.0);
                continue;
            }
            if (u == v) {
                res.push_back(1.0);
                continue;
            }

            visited.clear();
            visited.insert(u);
            res.push_back(dfs(u, v, 1.0));
        }
        return res;
    }
    private:
    unordered_map<string, vector<pair<string, double>>> graph;
    set<string> visited;
    double dfs(const string& src, const string& dest, double currProduct)
    {
        if (src == dest) return currProduct;

        for (auto& [v, weight] : graph[src]) {
            if (visited.count(v)) continue;
            visited.insert(v);
            double nextProduct = currProduct * weight;
            double res = dfs(v, dest, nextProduct);
            if (res != -1.0) return res;
            visited.erase(v);
        }

        return -1.0;
    }

    void buildGraph(vector<vector<string>>& equations, vector<double>& values)
    {
        int n = equations.size();
        for (int i=0; i<n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];

            graph[u].push_back( {v, values[i]} );
            graph[v].push_back( {u, 1.0 / values[i] });
        }
    }
};
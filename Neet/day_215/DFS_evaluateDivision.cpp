class Solution 
{
    public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
        vector<double>& values, vector<vector<string>>& queries) 
    {
        if (equations.empty() || values.empty() || queries.empty()) return {};
        buildGraph(equations, values);

        vector<double> res;
        for (auto& q : queries) {
            string src = q[0];
            string dest = q[1];
            res.push_back(dfs(src, dest, 1.0));
            visited.clear();
        }
        return res;
    }

    private:
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_set<string> visited;

    double dfs(const string& src, const string& dest, double currProduct)
    {
        if (!graph.count(src) || !graph.count(dest)) return -1.0;
        if (src == dest) return currProduct;
        visited.insert(src);

        for (auto& [v, weight] : graph[src]) {
            if (visited.count(v)) continue;
            double nextProduct = currProduct * weight;
            double res = dfs(v, dest, nextProduct);
            if (res != -1.0) return res;
        }
        return -1.0;
    }

    void buildGraph(vector<vector<string>>& equations, 
        vector<double>& values)
    {
        int n = equations.size();
        for (int i=0; i<n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            graph[u].push_back( {v, values[i]} ); // u / v 
            graph[v].push_back( {u, 1.0 / values[i]} ); // v / u
        }
    }
};
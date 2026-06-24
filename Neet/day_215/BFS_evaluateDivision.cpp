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
            res.push_back( bfs(src, dest) );
        }
        return res;
    }

    private:
    unordered_map<string, vector<pair<string, double>>> graph;
    double bfs(const string& src, const string& dest)
    {
        if (!graph.count(src) || !graph.count(dest)) return -1.0;
        queue<pair<string, double>> q;
        q.push( {src, 1.0} );
        unordered_set<string> visited;
        visited.insert(src);

        while (!q.empty()) {
            auto [currNode, currProduct] = q.front();
            q.pop();
            if (currNode == dest) return currProduct;
            for (auto& [v, weight] : graph[currNode]) {
                if (visited.count(v)) continue;
                double nextProduct = currProduct * weight;
                visited.insert(v);
                q.push( {v, nextProduct} );
            }
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
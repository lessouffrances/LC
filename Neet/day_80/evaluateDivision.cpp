class Solution 
{
    public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) 
    {
        if (equations.empty() || values.empty() || queries.empty()) return {};
        buildGraph(equations, values);

        vector<double> res;
        for (const auto& query : queries) {
            string start = query[0];
            string dest = query[1];

            if (!graph.count(start) || !graph.count(dest)) {
                res.push_back(-1.0);
            } else if (start == dest) {
                res.push_back(1.0);
            } else {
                res.push_back(bfs(start, dest));
            }
        }
        return res;
    }

    private:
    unordered_map<string, vector<pair<string, double>>> graph;
    double bfs(const string& start, const string& dest) 
    {
        unordered_set<string> visited;
        queue<pair<string, double>> q;

        q.push( {start, 1.0} );
        visited.insert(start);

        while (!q.empty()) {
            auto [node, product] = q.front();
            q.pop();

            if (node == dest) {
                return product;
            }

            for (const auto& [neighbor, weight] : graph[node]) {
                if (visited.find(neighbor) != visited.end()) continue;
                visited.insert(neighbor);
                q.push( {neighbor, product * weight} );
            }
        }
        return -1.0;
    }

    void buildGraph(vector<vector<string>>& equations, vector<double>& values)
    {
        for (int i=0; i<equations.size(); i++) {
            string& u = equations[i][0];
            string& v = equations[i][1];

            double weight = values[i];

            graph[u].push_back( {v, weight} );
            graph[v].push_back( {u, 1.0 / weight} );
        }
    }
};
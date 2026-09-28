class Solution 
{
    public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
        vector<double>& values, vector<vector<string>>& queries) 
    {
        if (equations.empty() || values.empty()) return {};
        buildGraph(equations, values);

        // BFS
        auto bfs = [&] (queue<pair<string, double>>& q, const string& src, const string& dest, unordered_set<string>& visited) -> double {
            q.push( {src, 1.0} );
            visited.insert(src);

            while (!q.empty()) {
                auto [u, product] = q.front(); q.pop();
                if (u == dest) return product;

                for (auto [v, weight] : graph[u]) {
                    if (visited.count(v)) continue;
                    q.push( {v, product * weight} );
                    visited.insert(v);
                }
            }
            return -1.0; // no connectivity
        };

        vector<double> res;
        for (auto& query : queries) {
            string src = query[0];
            string dest = query[1];

            string id = src+"->"+dest;
            if (cache.count(id)) {
                res.push_back(cache[id]);
                continue;
            }
            if (!graph.count(src) || !graph.count(dest)) {
                res.push_back(-1.0);
                continue;
            }

            queue<pair<string, double>> q;
            unordered_set<string> visited;
            double ans = bfs(q, src, dest, visited);
            cache[id] = ans;
            res.push_back(ans);
        }
        return res;
    }


    private:
    unordered_map<string, vector<pair<string, double>>> graph; 
    unordered_map<string, double> cache; 

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
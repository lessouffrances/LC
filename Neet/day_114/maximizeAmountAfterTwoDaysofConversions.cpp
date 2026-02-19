class Solution 
{
public:
    double maxAmount(string initialCurrency, 
        vector<vector<string>>& pairs1, vector<double>& rates1, 
        vector<vector<string>>& pairs2, vector<double>& rates2) 
    { 
        // Build 2 separate graphs
        buildGraph(pairs1, rates1, graph1);
        buildGraph(pairs2, rates2, graph2);

        // Day 1: BFS to find amount at each currency
        unordered_map<string, double> bankAccount;
        bankAccount[initialCurrency] = 1.0;
        
        for (auto& [curr, _] : graph1) {
            if (curr == initialCurrency) continue;
            double res = bfs(initialCurrency, curr, graph1);
            if (res != -1.0) {
                bankAccount[curr] = res;
            }
        }

        // Day 2: Convert back to initial currency
        double maxAmount = 1.0;
        for (auto& [curr, amount] : bankAccount) {
            double res = bfs(curr, initialCurrency, graph2);
            if (res != -1.0) {
                maxAmount = max(maxAmount, res * amount);
            }
        }
        return maxAmount;
    }
    
private:
    unordered_map<string, vector<pair<string, double>>> graph1;
    unordered_map<string, vector<pair<string, double>>> graph2;

    double bfs(const string& start, const string& end, 
               unordered_map<string, vector<pair<string, double>>>& graph) 
    {
        if (start == end) return 1.0;
        if (graph.find(start) == graph.end()) return -1.0;

        queue<pair<string, double>> q;
        q.push({start, 1.0});
        unordered_set<string> visited;
        visited.insert(start);

        while (!q.empty()) {
            auto [curr, amount] = q.front();
            q.pop();

            if (curr == end) return amount;

            for (auto& [nextCurr, rate] : graph[curr]) {
                if (visited.count(nextCurr)) continue;
                visited.insert(nextCurr);
                q.push({nextCurr, rate * amount});
            }
        }
        return -1.0;
    }
    
    void buildGraph(vector<vector<string>>& pairs, vector<double>& rates, 
                    unordered_map<string, vector<pair<string, double>>>& graph)  
    {
        if (pairs.empty() || rates.empty()) return;
        int n = pairs.size();

        for (int i = 0; i < n; i++) {
            string init = pairs[i][0];
            string end = pairs[i][1];
            graph[init].push_back({end, rates[i]});
            graph[end].push_back({init, 1.0 / rates[i]});
        }
    }
};
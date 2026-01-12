class Solution {
    public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        constructGraph(s, pairs);
      
        set<set<int>> collections;
        for (int i=0; i<s.length(); i++) {
            if (!visited.count(i)) {
                set<int> connectedComp;
                dfs(graph, i, connectedComp);
                collections.insert(connectedComp);
            } 
        }

        map<int, char> lookUp; 
        for (auto& collection : collections) {
            vector<int> sortedIdx;
            vector<char> sortedChar;
            for (int idx : collection) {
                sortedChar.push_back(s[idx]);
                sortedIdx.push_back(idx);
            }

            sort(sortedChar.begin(), sortedChar.end());
            for (int i=0; i<sortedChar.size(); i++) {
                lookUp.insert( {sortedIdx[i], sortedChar[i]} );
            }
        }

        // add isolated nodes into lookUp
        for (int i=0; i<s.length(); i++) {
            if (!lookUp.count(i)) {
                lookUp.insert( {i, s[i]} );
            }
        }

        string res = "";
        for (auto& [idx, ch] : lookUp) {
            res += ch;
        }
        return res;
    }
    private:
    set<int> visited;
    void dfs(unordered_map<int, vector<int>>& graph, int sourceIdx, set<int>& connectedComponent) 
    {
        connectedComponent.insert(sourceIdx);
        visited.insert(sourceIdx);

        if (graph.count(sourceIdx)) {
            for (auto& v : graph[sourceIdx]) {
                if (!visited.count(v)) {
                    dfs(graph, v, connectedComponent);
                }
            }
        }
    }

    unordered_map<int, vector<int>> graph;
    void constructGraph(string s, vector<vector<int>>& pairs)
    {
        if (pairs.empty()) return;

        for (int i=0; i<s.length(); i++) {
            graph[i] = {};
        }

        for (auto& pair : pairs) {
            int u = pair[0];
            int v = pair[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};
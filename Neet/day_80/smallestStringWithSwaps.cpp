class Solution 
{
    public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        constructGraph(pairs);
        for (int i=0; i<s.length(); i++) {
            if (visited.find(i) == visited.end()) {
                set<int> connectedComp;
                dfs(graph, i, connectedComp);
                collections.insert(connectedComp);
            }
        }

        unordered_map<int, char> lookUp;

        for (auto& collect : collections) {
            vector<int> sortedIdx(collect.begin(), collect.end());
            vector<char> sortedChar;
            for (int idx : collect) {
                sortedChar.push_back(s[idx]);
            }
            sort(sortedChar.begin(), sortedChar.end());

            for (int i=0; i<sortedChar.size(); i++) {
                lookUp.insert( {sortedIdx[i], sortedChar[i]} );
            }
        }

        // add isolated char into the lookUp
        for (int i=0; i<s.length(); i++) {
            if (!lookUp.count(i)) {
                lookUp.insert( {i, s[i]} );
            }
        }

        string res(s.length(), ' ');
        for (auto& [idx, ch] : lookUp) {
            res[idx] = ch;
        }
        return res;
    }

    private:
    unordered_map<int, vector<int>> graph; 
    set<int> visited;
    set<set<int>> collections;
    void dfs(unordered_map<int, vector<int>>& graph, int source, set<int>& connectedComponent)
    {
        connectedComponent.insert(source);
        visited.insert(source);

        if (graph.count(source)) {
            for (auto& v : graph[source]) {
                if (visited.find(v) == visited.end()) {
                    dfs(graph, v, connectedComponent);
                }
            }
        }
    }

    void constructGraph(vector<vector<int>>& pairs)
    {
        if (pairs.empty()) return;
        
        for (auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
    }
};

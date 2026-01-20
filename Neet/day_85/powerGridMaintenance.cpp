class Solution 
{
    public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) 
    {
        if (queries.empty()) return {}; 
        buildGraph(c, connections);
        // assign each CC with the same ID, queried by the ID in the lookup
        int componentID = 1;
        for (int station=1; station<=c; station++) {
            if (!visited.count(station)) {
                dfsAssignComponentID(station, graph, componentID);
                componentID++;
            }
        }

        // process queries
        vector<int> status;
        for (auto& query : queries) {
            int instru = query[0];
            int station = query[1];
            int ID = stationToID[station];

            if (instru == 1) {
                if (IDToActives[ID].count(station)) {
                    status.push_back(station);
                    continue;
                } else if (!IDToActives[ID].empty()) {
                    status.push_back(*IDToActives[ID].begin());
                    continue;
                } else {
                    status.push_back(-1);
                    continue;
                }
            } else if (instru == 2) {
                IDToActives[ID].erase(station);
            }
        }
        return status;
    }

    private:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> graph; 
    unordered_map<int, set<int>> IDToActives; //  { ID : components }
    unordered_map<int, int> stationToID; // { station : ID }
    void dfsAssignComponentID(int u, unordered_map<int, vector<int>>& graph, int componentID)
    {
        if (!u) return;

        IDToActives[componentID].insert(u);
        stationToID[u] = componentID;
        visited.insert(u);

        if (graph.count(u)) {
            for (auto& v : graph[u]) {
                if (!visited.count(v)) {
                    dfsAssignComponentID(v, graph, componentID);
                }
            }
        }
    }

    void buildGraph(int c, vector<vector<int>>& connections) 
    {
        for (auto& connect : connections) {
            int u = connect[0];
            int v = connect[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};
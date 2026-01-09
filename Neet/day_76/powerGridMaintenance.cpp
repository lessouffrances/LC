class Solution {
    public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) 
    {
        // construct the graph
        constructGraph(connections);

        int componentID = 0;
        for (int source=1; source<=c; source++) {
            if (!visited.count(source)) {
                dfsAssignComponentID(graph, source, componentID);
                componentID++;
            }
        }

        vector<int> res;
        for (auto& query : queries) {
            int instr = query[0];
            int station = query[1];
            if (instr == 1) {
                // check the station and collect the station
                // if station online
                int id = stationToID[station];
                if (IDToOnlineStations[id].count(station)) {
                    res.push_back(station);
                } else if (!IDToOnlineStations[id].empty()){
                    // if station offline
                    res.push_back(*IDToOnlineStations[id].begin()); // to return the frist one in the ordered_set
                } else {
                    res.push_back(-1);
                }
            } else if (instr == 2) {
                // offline the station
                int id = stationToID[station];
                IDToOnlineStations[id].erase(station);
            }
        }
        return res;
    }
    private:
    // find CC and the stations in the same CC should have the same component ID
    // dfs
    unordered_map<int, set<int>> IDToOnlineStations; // { id: ordered_set of stations }
    unordered_map<int, int> stationToID; // { station : id }
    unordered_set<int> visited; // visited source
    unordered_map<int, vector<int>> graph;
    void dfsAssignComponentID(unordered_map<int, vector<int>>& graph, int source, int componentID)
    {
        visited.insert(source);
        IDToOnlineStations[componentID].insert(source);
        stationToID[source] = componentID;

        if (graph.count(source)) {
            for (auto& dest : graph[source]) {
                if (!visited.count(dest)) {
                    dfsAssignComponentID(graph, dest, componentID);
                }
            }
        }
    }

    void constructGraph(vector<vector<int>>& connections) 
    {
        if (connections.empty()) return;
        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
};
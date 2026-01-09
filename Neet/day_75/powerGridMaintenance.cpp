// construct the graph using the connections
// if online, self
// if offline, smallest id by BFS
class Solution 
{
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries)
   {
      if (c == 0 || queries.empty()) {
         return {};
      }
      constructGraph(connections, c);
      vector<int> res;
      for (auto& query : queries) {
         int instr = query[0];
         int station = query[1];
         if (instr == 1) {
            if (offline.count(station)) {
               // BFS to find the connected which is not in offline
               // and with the smallest id
               res.push_back( bfs(graph, station) );
            } else {
               // online is self
               res.push_back(station);
            }
         } else if (instr == 2) {
            offline.insert(station);
         }
      }
      return res;
   }








private:
   unordered_map<int, vector<int>> graph;
   unoredered_set<int> offline;

   // only process online stations
   int bfs(unordered_map<int, vector<int>>& graph, int source)
   {
      queue<int> q;
      q.push(source);
      unordered_set<int> visited;
      visited.insert(source);
      int minConn = INT_MAX;
      bool found = false;
      while (!q.empty()) {
         int station = q.front();
         q.pop();
         if (graph.count(station)) {
            for (int v : graph[station]) {
               if (visited.find(v) != visited.end()) continue;
               // if online 
               if (!offline.count(v)) {
                  minConn = min(minConn, v);
                  found = true;
               } 
               q.push(v);
               visited.insert(v);
            }
         }
      }
      return found ? minConn : -1;
   }

   void constructGraph(vector<vector<int>>& connections, int c)
   {
      if (connections.empty()) return;
      for (int i=1; i<=c; i++) {
         graph[i] = {};
      }
      for (auto& conn : connections) {
         int u = conn[0];
         int v = conn[1];
         graph[u].push_back(v);
         graph[v].push_back(u);
      }
   }
};

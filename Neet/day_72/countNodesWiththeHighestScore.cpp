class Solution 
{
public:
   int countHighestScoreNodes(vector<int>& parents) 
   {
        
   }
};
// use FULL DFS is too slow
class Solution 
{
public:
   unordered_map<int, vector<int>> adjList;
   int countHighestScoreNodes(vector<int>& parents) 
   {
      if (parents.empty()) return 0;
      constructAdjList(parents);
      int n = parents.size();
      map<long long, int> lookUp; // { score, count }
      for (int par=0; par<n; par++) {
         if (adjList.find(par) != adjList.end()) {
            // node is a leaf
            if (adjList[par].size() == 0) {
               lookUp[n-1]++;
               continue;
            }
            // node is not a leaf
            long long temp = 1;
            int subtreeSize = 0;
            for (int child : adjList[par]) {
               int size = dfs(child);
               temp = temp * size;
               subtreeSize += size;
            }
            int remaining = n-subtreeSize-1;
            if (remaining > 0) {
               temp *= remaining;
            }
            lookUp[temp]++;
         }
      }
      return lookUp.rbegin()->second;        
   }
private:
   // For each node, you need to find the sizes of the subtrees rooted in each of its children.
   int dfs(int u) 
   {
      int res = 1; 
      if (adjList.find(u) != adjList.end()) {
         for (int v : adjList[u]) {
            res += dfs(v);
         }
      }
      return res;
   }
   void constructAdjList(vector<int>& parents) {
      int n = parents.size();
      for (int i = 0; i < n; i++) {
         adjList[i] = {};
      }
      for (int node=1; node<n; node++) {
         adjList[parents[node]].push_back(node);
      }
   }
};

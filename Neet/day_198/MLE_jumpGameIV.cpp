class Solution 
{
    public:
    int minJumps(vector<int>& arr) 
    {
        if (arr.empty()) return -1;
        buildGraph(arr);

        int n = arr.size();
        int steps = 0;
        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);

        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currPos = q.front();
                q.pop();

                if (currPos == n-1) return steps;
                for (int nextPos : graph[currPos]) {
                    if (visited.count(nextPos)) continue;
                    q.push(nextPos);
                    visited.insert(nextPos);
                }
            }
            steps++;
        }
        return -1;
    }
    private:
    unordered_map<int, vector<int>> graph;
    void buildGraph(vector<int>& arr)
    {
        int n = arr.size();
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i != j && arr[i] == arr[j]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
                if (i-1>=0) {
                    graph[i].push_back(i-1);
                } 
                if (i+1<n) {
                    graph[i].push_back(i+1);
                }
            }
        }
    }
};
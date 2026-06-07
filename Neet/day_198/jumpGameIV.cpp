class Solution 
{
    public:
    int minJumps(vector<int>& arr) 
    {
        if (arr.empty()) return -1;
        int n = arr.size();

        // collect adjList based on the same value
        unordered_map<int, vector<int>> adjList; // valToIdx
        for (int i=0; i<n; i++) {
            adjList[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        unordered_set<int> visited;
        visited.insert(0);

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto currPos = q.front();
                q.pop();

                if (currPos == n-1) return steps;

                // try currPos-1 and currPos+1
                if (currPos-1>=0 && !visited.count(currPos-1)) {
                    q.push(currPos-1);
                    visited.insert(currPos-1);
                }
                if (currPos+1<n && !visited.count(currPos+1)) {
                    q.push(currPos+1);
                    visited.insert(currPos+1);
                } 
                for (int j : adjList[arr[currPos]]) {
                    if (visited.count(j)) continue;
                    q.push(j);
                    visited.insert(j);
                }
                adjList.erase(arr[currPos]); // without it, TLE
            }
            steps++;
        }
        return -1;
    }
};
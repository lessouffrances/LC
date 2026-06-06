// i + 1 where: i + 1 < arr.length.
// i - 1 where: i - 1 >= 0.
// j where: arr[i] == arr[j] and i != j.

class Solution 
{
    public:
    int minJumps(vector<int>& arr) 
    {
        if (arr.size() == 1) return 0;
        int n = arr.size();

        unordered_map<int, vector<int>> graph; //valToIdx
        for (int i=0; i<n; i++) {
            graph[arr[i]].push_back(i); 
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

                // currPos+1
                if (currPos+1<n && !visited.count(currPos+1)) {
                    q.push(currPos+1);
                    visited.insert(currPos+1);
                } 

                // currPos-1
                if (currPos-1>=0 && !visited.count(currPos-1)) {
                    q.push(currPos-1);
                    visited.insert(currPos-1);
                }

                // arr[i] == arr[j] and i != j
                auto& sameValIdxes = graph[arr[currPos]];
                for (int idx : sameValIdxes) {
                    if (visited.count(idx)) continue;
                    q.push(idx);
                    visited.insert(idx);
                }
                graph.erase(arr[currPos]);
            }
            steps++;
        }
        return -1;
    }
};
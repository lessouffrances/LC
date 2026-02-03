class Solution 
{
    public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        if (routes.empty()) return 0;
        if (source == target) return 0;
        int n = routes.size();

        // build stopToBuses
        unordered_map<int, vector<int>> stopToBuses;
        for (int i=0; i<n; i++) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }

        // push all buses passing thru source onto q
        queue<int> q;
        unordered_set<int> visited;
        for (int bus : stopToBuses[source]) {
            q.push(bus);
            visited.insert(bus);
        }

        int numOfBuses = 0;
        while (!q.empty()) {
            int size = q.size();
            numOfBuses++;

            for (int i=0; i<size; i++) {
                auto bus = q.front();
                q.pop();

                // if this bus reaches target
                if (binary_search(stopToBuses[target].begin(), stopToBuses[target].end(), bus)) return numOfBuses;

                for (int nextStation : routes[bus]) {
                    for (int nextBus : stopToBuses[nextStation]) {
                        if (visited.count(nextBus)) continue;
                        q.push(nextBus);
                        visited.insert(nextBus);
                    }
                }
            }
        }
        return -1;
    }
};
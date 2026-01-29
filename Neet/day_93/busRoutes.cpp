class Solution 
{
    public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target)
    {
        if (routes.empty()) return 0;
        if (source == target) return 0;

        // build stopToBuses lookup table
        unordered_map<int, unordered_set<int>> stopToBuses;
        for (int bus=0; bus<routes.size(); bus++) {
            for (int stop : routes[bus]) {
                stopToBuses[stop].insert(bus);
            }
        }

        // push all buses passing thru the start onto the q
        queue<int> q;
        unordered_set<int> visited;
        for (int bus : stopToBuses[source]) {
            q.push(bus);
            visited.insert(bus);
        }

        int numOfBuses = 1; 
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto bus = q.front();
                q.pop();

                // if this bus passes thru the target
                if (stopToBuses[target].count(bus)) return numOfBuses;

                // push buses who (shares stops with this bus && not visited) 
                for (int stop : routes[bus]) {
                    for (int bus : stopToBuses[stop]) {
                        if (!visited.count(bus)) {
                            q.push(bus);
                            visited.insert(bus);
                        }
                    }
                }
            }
            numOfBuses++;
        }
        return -1;
    }
};
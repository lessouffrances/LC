class Solution 
{
    public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        if (routes.empty()) return -1;
        if (source == target) return 0;
        buildStopToBuses(routes);
        int n = routes.size();
        
        // BFS on buses
        queue<int> q;
        unordered_set<int> visitedBuses;
        unordered_set<int> visitedStops;

        // push all the buses passing through the source on the q
        for (int bus : stopToBuses[source]) {
            q.push(bus);
            visitedBuses.insert(bus);
        }

        int numBuses = 1;
        while (!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                auto bus = q.front();
                q.pop();

                // check all the stops that this bus is on
                for (int stop : routes[bus]) {
                    if (stop == target) return numBuses;

                    if (visitedStops.count(stop)) continue;
                    visitedStops.insert(stop);

                    for (int nextBus : stopToBuses[stop]) {
                        if (visitedBuses.count(nextBus)) continue;
                        visitedBuses.insert(nextBus);
                        q.push(nextBus);
                    }
                }
            }
            numBuses++;
        }
        return -1;
    }
    private:
    unordered_map<int, vector<int>> stopToBuses; // { stop : buses to the stop }
    void buildStopToBuses(vector<vector<int>>& routes)
    {
        if (routes.empty()) return;
        for (int bus=0; bus<routes.size(); bus++) {
            for (int stop : routes[bus]) {
                stopToBuses[stop].push_back(bus);
            }
        }
    }
};
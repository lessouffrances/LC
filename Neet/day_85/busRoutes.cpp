class Solution 
{
    public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) 
    {
        if (routes.empty()) return -1;
        if (source == target) return 0;

        buildStopToBuses(routes);

        // BFS on bus, push all buses that pass through the source onto the q
        queue<int> q;
        unordered_set<int> visitedBuses;
        unordered_set<int> visitedStops;
        visitedStops.insert(source);
        for (int bus : stopToBuses[source]) {
            q.push(bus);
            visitedBuses.insert(bus);
        }
        
        int numBuses = 0;
        while (!q.empty()) {
            int size = q.size();
            numBuses++;
            
            for (int i=0; i<size; i++) {
                auto bus = q.front();
                q.pop();

                if (stopToBuses[target].count(bus)) return numBuses;

                // next station reachable
                for (int stop : routes[bus]) {
                    if (visitedStops.count(stop)) continue;
                    visitedStops.insert(stop);
                    for (int bus : stopToBuses[stop]) {
                        if (visitedBuses.count(bus)) continue;
                        q.push(bus);
                        visitedBuses.insert(bus);
                    }
                }
            }
        }
        return -1;
    }

    private:
    unordered_map<int, unordered_set<int>> stopToBuses; // { stop : buses }
    void buildStopToBuses(vector<vector<int>>& routes)
    {
        if (routes.empty()) return;

        int n = routes.size();
        for (int bus=0; bus<n; bus++) {
            for (int stop : routes[bus]) {
                stopToBuses[stop].insert(bus);
            }
        }
    }
};
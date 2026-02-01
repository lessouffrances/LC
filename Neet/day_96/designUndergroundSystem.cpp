class UndergroundSystem 
{
    public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) 
    {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        auto [start, checkInTime] = checkIns[id];
        string route = makeRoute(start, stationName);
        int travelTime = t - checkInTime;
        routesStats[route].first += travelTime;
        routesStats[route].second += 1;
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string key = makeRoute(startStation, endStation);
        return (double) routesStats[key].first / routesStats[key].second;

    }
    private:
    unordered_map<int, pair<string, int>> checkIns;  // { id, { startStation, checkInTime} }
    unordered_map<string, pair<int, int>> routesStats; // { route, { totalTravelTime, totalTripCount } }

    string makeRoute(string& startStation, string& endStation)
    {
        return startStation + "->" + endStation;
    }
};
    
    
class UndergroundSystem 
{
    public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) 
    {
        if (inTransit.count(id)) return;
        inTransit[id] = { stationName, t };
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        if (!inTransit.count(id)) return;
        auto [inStation, checkInTime] = inTransit[id];
        routeStats[makeRoute(inStation, stationName)].first += 1;
        routeStats[makeRoute(inStation, stationName)].second += (t-checkInTime);
        inTransit.erase(id);
    }

    double getAverageTime(string startStation, string endStation) 
    {
        string route = makeRoute(startStation, endStation);
        if (routeStats.count(route)) {
            auto [numberOfTrips, totalTime] = routeStats[route];
            return (double) totalTime / numberOfTrips;
        }
        return 0.0;
    }

    string makeRoute(const string& inStation, const string& outStation)
    {
        return inStation+"->"+outStation;
    }

    private:
    unordered_map<string, pair<int, int>> routeStats; // route : {numberOfTrips, totalTime} 
    unordered_map<int, pair<string, int>> inTransit; // id: {inStation, checkInTime}
}; 
    
   
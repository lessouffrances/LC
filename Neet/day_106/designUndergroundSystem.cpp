class UndergroundSystem 
{
    public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) 
    {
        checkIns[id] = { stationName, t };
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        string startStation = checkIns[id].first;
        int checkInTime = checkIns[id].second;
        routeStats[makeRoute(startStation, stationName)].first += (t - checkInTime);
        routeStats[makeRoute(startStation, stationName)].second++;
        checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        int totalTravelTime = routeStats[makeRoute(startStation, endStation)].first;
        int totalTripCount = routeStats[makeRoute(startStation, endStation)].second;

        return (double) totalTravelTime / totalTripCount;
    }
    private:
    string makeRoute(const string& startStation, const string& endStation)
    {
        return startStation + "->" + endStation;
    }
    unordered_map<int, pair<string, int>> checkIns; // id : { stationName, checkinTime }
    unordered_map<string, pair<int, int>> routeStats; // route : { totalTravelTime, totalTripCount }
};
    
    
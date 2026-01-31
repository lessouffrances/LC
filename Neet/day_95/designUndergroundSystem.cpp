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
        auto [startStation, checkInTime] = checkIns[id];
        checkIns.erase(id);

        int travelTime = t - checkInTime;
        string route = makeRoute(startStation, stationName);
        routesStats[route].first += travelTime;
        routesStats[route].second++;
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string route = makeRoute(startStation, endStation);
        auto [totalTravelTime, totalCount] = routesStats[route];
        return (double) totalTravelTime / totalCount;
    }
    private:
    unordered_map<int, pair<string, int>> checkIns;  // { id : { startStation, checkInTime } }
    unordered_map<string, pair<int, int>> routesStats; // { route : { totalTime, tripCount } }

    string makeRoute(string startStation, string endStation) 
    {
        return startStation + "->" + endStation;
    }

};
    
    /**
     * Your UndergroundSystem object will be instantiated and called as such:
     * UndergroundSystem* obj = new UndergroundSystem();
     * obj->checkIn(id,stationName,t);
     * obj->checkOut(id,stationName,t);
     * double param_3 = obj->getAverageTime(startStation,endStation);
     */
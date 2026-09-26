class UndergroundSystem 
{
    public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) 
    {
        if (inTransit.count(id)) return;
        inTransit[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        if (!inTransit.count(id)) return;
        auto [inStation, checkInTime] = inTransit[id];
        string route = makeRoute(inStation, stationName);
        routeStats[route].first++;
        routeStats[route].second += (t-checkInTime);

        inTransit.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        string route = makeRoute(startStation, endStation);
        int totalNumOfTrips = routeStats[route].first;
        int totalTimeOfTrips = routeStats[route].second;
        return (double) totalTimeOfTrips/totalNumOfTrips;
    }

    private:
    unordered_map<int, pair<string, int>> inTransit; // id : {inStation, checkInTime} 
    unordered_map<string, pair<int, int>> routeStats; // route : {numberOfTrips, totalTime} 

    string makeRoute(const string& in, const string& out)
    {
        return in+"->"+out;
    }
};
    
   
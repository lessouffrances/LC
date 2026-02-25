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
        string start = checkIns[id].first;
        int checkInTime = checkIns[id].second;

        string route = makeRoute(start, stationName);
        routeStats[route].first += (t - checkInTime);
        routeStats[route].second++;
        checkIns.erase(id);
    }
    double getAverageTime(string startStation, string endStation) 
    {
        string route = makeRoute(startStation, endStation);
        int totalTravelTime = routeStats[route].first;
        int numOfTrips = routeStats[route].second;
        return (double) totalTravelTime / numOfTrips;
    }
    private:
    unordered_map<int, pair<string, int>> checkIns; // { id : { stationName, checkInTime } }
    unordered_map<string, pair<int, int>> routeStats; // { route : { totalTravelTime, totalTripCount } }

    string makeRoute(string startStation, string endStation) 
    {
        return startStation + "->" + endStation;
    }
};
    
   
class Solution 
{
    public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        if (costs.empty()) return 0;
        int n = costs.size();

        // the upfront ones are those who should go to a city
        sort(costs.begin(), costs.end(), [](const auto& a, const auto& b){
            return a[0]-a[1] < b[0]-b[1];
        });

        // once we sort this way, the people who should go to a city 
        // will be the first half for the array
        int totalCost = 0;
        for (int i=0; i<n/2; i++) {
            totalCost += costs[i][0];
        }
        for (int i=n/2; i<n; i++) {
            totalCost += costs[i][1];
        }
        return totalCost;
    }
};
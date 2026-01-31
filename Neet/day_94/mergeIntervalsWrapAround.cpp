

struct Info
{
    bool isWrapped = false;
    vector<vector<int>> res;
};

class Solution 
{
    public:
    bool merge(vector<vector<int>>& restaurantIntervals, 
        vector<vector<int>>& groceryIntervals) 
    {
        if (restaurantIntervals.empty() || groceryIntervals.empty()) return false;

        vector<vector<int>> processedRestaurantIntervals = processedIntervals(restaurantIntervals);
        vector<vector<int>> processedGroceryIntervals = processedIntervals(groceryIntervals);

        vector<pair<int, vector<int>>> labelledRestaurantIntervals = labelIntervals(processedRestaurantIntervals);
        vector<pair<int, vector<int>>> labelledGroceryIntervals = labelIntervals(processedGroceryIntervals);

        labelledRestaurantIntervals.insert(labelledRestaurantIntervals.begin(), labelledGroceryIntervals.begin(), labelledGroceryIntervals.end());


        sort(labelledRestaurantIntervals.begin(), labelledRestaurantIntervals.end(), [](const auto& a, const auto& b){
            return a.second[0] < b.second[0];
        });

        pair<int, vector<int>> prevInterval = labelledRestaurantIntervals[0];
        for (int i=1; i<labelledRestaurantIntervals.size(); i++) {
            pair<int, vector<int>> currInterval = labelledRestaurantIntervals[i];
            if (currInterval.first != prevInterval.first && currInterval.second[0] < prevInterval.second[1]) {
                return true;
            }
        }
        return false;
    }

    private:
    Info checkBreakDownWrapRound(vector<int>& interval)
    {
        Info info;
        if (interval[1] < interval[0]) {
            info.isWrapped = true;
            info.breakDowns = { {interval[0], 24}, {0, interval[1]} };
        }
    }

    vector<vector<int>> processIntevals(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> resIntervals;
        for (int i=0; i<intervals.size(); i++) {
            Info info = checkBreakDownWrapRound(intervals[i]);
            if (info.isWrapped) {
                resIntervals.push_back(info.res[0], info.res[1]);
            } else {
                resIntervals.push_back(intervals[i]);
            }
        }

        // sort by startTime
        sort(resIntervals.begin(), resIntervals.end(), [](const auto& a, const auto& b){
            return a[0] < b[0];
        });
        return resIntervals;
    }

    vector<pair<int, vector<int>>> labelIntervals(vector<vector<int>>& intervals, int label)
    {

        vector<pair<int, vector<int>>> labelledIntervals;
        for (auto& inter : intervals) {
            labelIntervals.push_back( {label, intervals[i]} );
        }
        return labelledIntervals;
    }
};

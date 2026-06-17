class Solution {
    public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
        vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int m = landDuration.size();
        int n = waterDuration.size();

        // land first
        int landEndTime = INT_MAX;
        for (int i=0; i<m; i++) {
            landEndTime = min(landEndTime, (landStartTime[i]+landDuration[i]));
        }

        int res1 = INT_MAX;
        for (int j=0; j<n; j++) {
            res1 = min(res1, max(landEndTime, waterStartTime[j])+waterDuration[j]);
        }

        // water first
        int waterEndTime = INT_MAX;
        for (int j=0; j<n; j++) {
            waterEndTime = min(waterEndTime, (waterStartTime[j]+waterDuration[j]));
        }

        int res2 = INT_MAX;
        for (int i=0; i<m; i++) {
            res2 = min(res2, max(waterEndTime, landStartTime[i])+landDuration[i]);
        }

        return min(res1, res2);
    }
};
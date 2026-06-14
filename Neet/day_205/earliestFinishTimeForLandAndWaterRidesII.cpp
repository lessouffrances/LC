class Solution 
{
    public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
        vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        int m = landDuration.size();
        int n = waterDuration.size();

        // land first
        int landEndTime1 = INT_MAX;
        int waterEndTime1 = INT_MAX;
        for (int i=0; i<m; i++) {
            landEndTime1 = min(landEndTime1, landStartTime[i]+landDuration[i]);
        }
        for (int j=0; j<n; j++) {
            waterEndTime1 = min(waterEndTime1, max(landEndTime1, waterStartTime[j])+waterDuration[j]);
        }

        // water first
        int waterEndTime2 = INT_MAX;
        int landEndTime2 = INT_MAX;
        for (int i=0; i<n; i++) {
            waterEndTime2 = min(waterEndTime2, waterStartTime[i]+waterDuration[i]);
        }
        for (int j=0; j<m; j++) {
            landEndTime2= min(landEndTime2, max(waterEndTime2, landStartTime[j])+landDuration[j]);
        }
        return min(waterEndTime1, landEndTime2);
    }
};
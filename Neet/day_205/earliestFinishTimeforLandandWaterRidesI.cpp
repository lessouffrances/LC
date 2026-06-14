class Solution 
{
    public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
        vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        int m = landDuration.size();
        int n = waterDuration.size();

        int res = INT_MAX;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                // land first
                int landEndTime1 = landStartTime[i]+landDuration[i];
                int waterEndTime1 = max(waterStartTime[j], landEndTime1)+waterDuration[j];
                res = min(waterEndTime1, res);

                // water first
                int waterEndTime2 = waterStartTime[j]+waterDuration[j];
                int landEndTime2 = max(landStartTime[i], waterEndTime2)+landDuration[i];
                res = min(landEndTime2, res);
            }
        }
        return res;
    }
};
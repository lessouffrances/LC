class Solution 
{
    public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
        vector<int>& waterStartTime, vector<int>& waterDuration) {

            int m = landDuration.size();
            int n = waterDuration.size();
            int finalEndTime = INT_MAX;

            for (int i=0; i<m; i++) {
                for (int j=0; j<n; j++) {
                    // land first
                    int landEndTime1 = landStartTime[i]+landDuration[i];
                    int waterEndTime1 = max(waterStartTime[j], landEndTime1)+waterDuration[j];
                    finalEndTime = min(finalEndTime, waterEndTime1);

                    // water first
                    int waterEndTime2 = waterStartTime[j]+waterDuration[j];
                    int landEndTime2 = max(waterEndTime2, landStartTime[i])+landDuration[i];
                    finalEndTime = min(finalEndTime, landEndTime2);
                }
            }
            return finalEndTime;
    }
};
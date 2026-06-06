class Solution 
{
    public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
        vector<int>& waterStartTime, vector<int>& waterDuration) {

            int n = landStartTime.size();
            int m = waterStartTime.size();

            // Option 1: land => water
            // land first
            int currTime1 = INT_MAX;
            for (int i=0; i<n; i++) {
                currTime1 = min(currTime1, landStartTime[i]+landDuration[i]);
            }

            // then water 
            int endTime1 = INT_MAX;
            for (int j=0; j<m; j++) {
                endTime1 = min(endTime1, max(currTime1, waterStartTime[j])+waterDuration[j]);
            }

            // Option 2: water => land
            // water first
            int currTime2 = INT_MAX;
            for (int i=0; i<m; i++) {
                currTime2 = min(currTime2, waterStartTime[i]+waterDuration[i]);
            }

            // then land
            int endTime2 = INT_MAX;
            for (int j=0; j<n; j++) {
                endTime2 = min(endTime2, max(currTime2, landStartTime[j])+landDuration[j]);
            }

            return min(endTime1, endTime2);
    }
};
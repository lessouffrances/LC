class Solution {
    public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
        vector<int>& waterStartTime, vector<int>& waterDuration) {

            // if do land first
            int n = landStartTime.size();
            int m = waterStartTime.size();

            int res = INT_MAX;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    // water first
                    int endWaterTime1 = waterStartTime[j] + waterDuration[j];
                    int endLandTime1 = max(endWaterTime1, landStartTime[i]) + landDuration[i];

                    res = min(res, endLandTime1);

                    // land first
                    int endLandTime2 = landStartTime[i] + landDuration[i];
                    int endWaterTime2 = max(endLandTime2, waterStartTime[j]) + waterDuration[j];

                    res = min(res, endWaterTime2);
                }
            }
            return res;
        }
    };
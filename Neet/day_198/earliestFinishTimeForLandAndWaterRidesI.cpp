class Solution {
    public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
        vector<int>& waterStartTime, vector<int>& waterDuration) {

        int m = landStartTime.size();
        int n = waterStartTime.size();

        int res = INT_MAX;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                // land first
                int landEndTime = landStartTime[i]+landDuration[i];
                int res1 = max(waterStartTime[j], landEndTime)+waterDuration[j];
                res = min(res, res1);

                // water first
                int waterEndTime = waterStartTime[j]+waterDuration[j];
                int res2 = max(landStartTime[i], waterEndTime)+landDuration[i];
                res = min(res, res2);
            }
        }
        return res;
    }
};
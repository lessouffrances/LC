class Solution
{
    public:
    int finalInstances(int instances, vector<int> averageUtil) 
    {
        if (averageUtil.empty()) return instances;

        int n = averageUtil.size();
        int i = 0;
        bool isIdle = false;

        while (i<n) {
            if (averageUtil[i] >= 25 && averageUtil[i] <= 60) {
                i++;
                continue;
            } else if (averageUtil[i] < 25 && instances > 1) {
                isIdle = true;
                instances = (instances+1) / 2;
            } else if (averageUtil[i] > 60 && instances <= pow(8, 10)) {
                isIdle = true;
                instances = 2*instances;
            } else {
                i++;
                continue;
            }

            if (isIdle) {
                i += 10;
                isIdle = false;
            } 
        }
        return instances;
    }
};
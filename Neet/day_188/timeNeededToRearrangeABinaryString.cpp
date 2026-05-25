class Solution 
{
    public:
    int secondsToRemoveOccurrences(string s) 
    {
        if (s.empty()) return 0;
        int n = s.length();
        int res = 0;

        int zerosCount = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '0') {
                zerosCount++;
            } else if (zerosCount > 0) {
                res = max(res+1, zerosCount);
            }
        }
        return res;
    }
};
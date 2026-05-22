class Solution 
{
    public:
    int secondsToRemoveOccurrences(string s) 
    {
        int res = 0;
        int zerosCount = 0;
        for (int i=0; i<s.length(); i++) {
            if (s[i] == '0') {
                zerosCount++;
            } else if (zerosCount > 0) {
                res = max(res+1, zerosCount);
            }
        }
        return res;
    }
};
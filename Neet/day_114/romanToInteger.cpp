



class Solution 
{
    public:int romanToInt(string s) 
    {
        unordered_map<char, int> symbolToVal =
        {
            {'I',1}, 
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int n = s.length();
        int res = 0;
        for (int i=0; i<n; i++) {
            if (i+1 < n && symbolToVal[s[i]] < symbolToVal[s[i+1]]) {
                res -= symbolToVal[s[i]];
            } else {
                res += symbolToVal[s[i]];
            }
        }
        return res;
    }
};
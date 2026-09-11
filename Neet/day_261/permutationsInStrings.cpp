class Solution 
{
    public:
    bool checkInclusion(string s1, string s2) 
    {
        if (s1.length() > s2.length()) return false;
        vector<int> s1Counter = getCounter(s1);
        int windowLen = s1.length();

        for (int start=0; start+windowLen <= s2.length(); start++) {
            string window = s2.substr(start, windowLen);
            if (getCounter(window) == s1Counter) return true;
        }
        return false;
    }

    private:
    vector<int> getCounter(const string& s)
    {
        vector<int> metric(26, 0);
        for (char ch : s) {
            metric[ch-'a']++;
        }
        return metric;
    }
};
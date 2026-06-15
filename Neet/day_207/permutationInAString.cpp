class Solution 
{
    public:
    bool checkInclusion(string s1, string s2) 
    {
        vector<int> s1Counter = getCounter(s1);
        int n = s2.length();
        int m = s1.length();
        for (int i=0; i<n; i++) {
            string sub = s2.substr(i, m);
            if (getCounter(sub) == s1Counter) return true;
        }
        return false;
    }

    private:
    vector<int> getCounter(const string& s)
    {
        if (s.length() == 0) return {};
        vector<int> counter(26, 0);
        for (char ch : s) {
            counter[ch-'a']++;
        }
        return counter;
    }
};
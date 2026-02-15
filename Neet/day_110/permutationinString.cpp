





class Solution 
{
    public:
    bool checkInclusion(string s1, string s2) 
    {
        if (s1.length() > s2.length()) return false;
        int n = s2.length();
        int m = s1.length();

        vector<int> benchmark = produceCounter(s1);
        for (int i=0; i<n-m+1; i++) {
            string subStr = s2.substr(i, m);
            if (produceCounter(subStr) == benchmark) return true;
        }
        return false;
    }
    private:
    vector<int> produceCounter(string& s)
    {
        vector<int> metric(26, 0);
        for (char ch : s) {
            metric[ch-'a']++;
        }
        return metric;
    }
};
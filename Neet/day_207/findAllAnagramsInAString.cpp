class Solution 
{
    public:
    vector<int> findAnagrams(string s, string p) 
    {
        int anagramSize = p.size();
        vector<int> benchmark = getCounter(p);

        vector<int> res;
        for (int i=0; i<s.length(); i++) {
            string subStr = s.substr(i, anagramSize);
            if (getCounter(subStr) == benchmark) {
                res.push_back(i);
            }
        }
        return res;
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
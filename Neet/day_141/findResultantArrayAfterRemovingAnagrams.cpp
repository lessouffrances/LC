class Solution 
{
    public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        if (words.empty()) return {};
        int n = words.size();

        vector<string> res = { words[0] };
        for (int i=1; i<n; i++) {
            if (!isAnagrams(words[i], res.back())) {
                res.push_back(words[i]);
            }
        }
        return res;
    }
    private:
    bool isAnagrams(const string& t, const string& s)
    {
        if (s.length() != t.length()) return false;
        int n = s.length();
        vector<int> sCounter(26, 0);
        vector<int> tCounter(26, 0);

        for (int i=0; i<n; i++) {
            sCounter[s[i]-'a']++;
            tCounter[t[i]-'a']++;
        }
        return sCounter == tCounter;
    }
};
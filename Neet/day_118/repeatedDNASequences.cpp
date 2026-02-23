






class Solution 
{
    public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        unordered_set<string> seenDNA;
        unordered_set<string> res;

        int n = s.length();
        for (int i=0; i+10<=n; i++) {
            string sub = s.substr(i, 10);
            if (seenDNA.count(sub)) {
                res.insert(sub);
            } else {
                seenDNA.insert(sub);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
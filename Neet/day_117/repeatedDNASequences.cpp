class Solution 
{
    public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        unordered_set<string> seen; 
        unordered_set<string> res;
        for (int i = 0; i + 10 <= s.size(); i++) {
            string sub = s.substr(i, 10);
            if (seen.count(sub)) {
                res.insert(sub);
            } else {
                seen.insert(sub);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
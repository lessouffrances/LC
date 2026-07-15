class Solution 
{
    public:
    bool differByOne(vector<string>& dict) 
    {
        unordered_set<string> seen;

        for (auto& word : dict) {
            for (int idx=0; idx<word.size(); idx++) {
                string masked = word.substr(0, idx)+"*"+word.substr(idx+1);
                if (seen.count(masked)) return true;
                seen.insert(masked);
            }
        }
        return false;
    }
};
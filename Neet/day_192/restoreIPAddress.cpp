class Solution 
{
    public:
    vector<string> restoreIpAddresses(string s) 
    {
        if (s.length() < 4 || s.length() > 12) return {};
        dfs(0, 0, "", s);
        return res;
    }
    private:
    vector<string> res;
    void dfs(int currIdx, int partCount, string currPath, string s) 
    {
        if (partCount == 4 && currIdx == s.length()) {
            res.push_back(currPath. substr(1)); // remove leading dot for the first 
            return;
        }
        if (partCount == 4 || currIdx == s.length()) return; // no valid IP address
        
        string currStr = "";
        for (int i=currIdx; i<min(currIdx+3, (int)s.length()); i++) {
            currStr += s[i];
            int currNum = stoi(currStr);
            if (currNum > 255) break;
            // do not accept leading zeros
            if (currStr.length() > 1 && currStr[0] == '0') break;
            dfs(i+1, partCount + 1, currPath + "." + currStr, s);
        }
    }
};
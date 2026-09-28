class Solution 
{
    public:
    vector<string> restoreIpAddresses(string s) 
    {
        // impossible to divide into valid IP address
        if (s.length() < 4 || s.length() > 12) return {};

        dfs(0, "", 0, s);
        return res;
    }

    private:
    vector<string> res;
    void dfs(int currIdx, string currPath, int groups, const string s)
    {
        if (groups == 4 && currIdx == s.length()) {
            res.push_back(currPath.substr(1));
            return;
        }

        if (groups == 4 || currIdx == s.length()) return;

        string currStr = "";
        // the cap is important
        for (int i=currIdx; i<min(currIdx+3, (int)s.length()); i++) {
            currStr += s[i];
            int currNum = stoi(currStr);
            if (currNum > 255) break;
            if (currStr.length() > 1 && currStr[0] == '0') break;
            dfs(i+1, currPath + "." + currStr, groups+1, s);
        }
    }
};
=class Solution 
{
    public:
    vector<string> restoreIpAddresses(string s) 
    {
        if (s.length() == 0) return {};
        string currPath = "";
        dfs(0, currPath, 0, s);
        return res;
    }

    private:
    vector<string> res;
    void dfs(int currIdx, string currPath, int groups, const string& s)
    {
        if (currIdx == s.length() && groups == 4) {
            res.push_back(currPath.substr(1));
            return;
        }

        if (currIdx == s.length() || groups == 4) return;

        string currStr = "";
        for (int i=currIdx; i<min(currIdx+3, (int)s.length()); i++) {
            currStr += s[i];
            int currNum = stoi(currStr);
            if (currNum > 255) break; // all the path here are too big
            if (currStr.length() > 1 && currStr[0] == '0') break; // the leading zero issue
            dfs(i+1, currPath + "." + currStr, groups+1, s);
        }
    }
};
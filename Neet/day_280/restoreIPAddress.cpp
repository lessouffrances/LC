




class Solution 
{
    public:
    vector<string> restoreIpAddresses(string s) 
    {
        // max length is 3 * 4 = 12
        if (s.length() > 12) return {};
        string currPath = "";
        dfs(0, currPath, 0, s);
        return res;
    }

    private:
    vector<string> res;

    void dfs(int currIdx, string currPath, int groups, string s)
    {
        if (groups == 4 && currIdx == s.length()) {
            res.push_back(currPath.substr(1));
            return;
        }

        if (groups == 4 || currIdx == s.length()) {
            return;
        }

        string currStr = "";
        for (int i=currIdx; i<min(i+3, (int)s.length()); i++) {
            currStr += s[i];
            if (currStr.length() > 1 && currStr[0] == '0') break;
            int currNum = stoi(currStr);
            if (currNum > 255) break;
            dfs(i+1, currPath + "." + currStr, groups+1, s);
        }
    }
};
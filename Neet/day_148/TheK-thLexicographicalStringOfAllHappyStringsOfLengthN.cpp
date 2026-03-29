


class Solution 
{
    public:
    string getHappyString(int n, int k) 
    {
        dfs(n, "");
        sort(res.begin(), res.end());
        return res.size() >= k ? res[k-1] : ""; 
    }
    private:
    vector<string> res;
    void dfs (int n, string currPath)
    {
        if (currPath.length() == n) {
            res.push_back(currPath);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (currPath.empty() || ch != currPath.back()) {
                currPath.push_back(ch);
                dfs(n, currPath);
                currPath.pop_back();
            }
        }
    }
};
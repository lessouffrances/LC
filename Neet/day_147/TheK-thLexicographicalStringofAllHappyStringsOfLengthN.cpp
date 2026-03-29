class Solution 
{
    public:
    string getHappyString(int n, int k) 
    {
        if (n == 0) return "";

        dfs("", n);
        return k > res.size() ? "" : res[k-1];
    }
    private:
    vector<string> happyStrings;

    void dfs(string currPath, int n) 
    {
        if (currPath.size() == n) {
            happyStrings.push_back(currPath);
            return;
        }
        for (char ch : {'a', 'b', 'c'}) {
            if (currPath.empty() || currPath.back() != ch) {
                currPath.push_back(ch);
                dfs(currPath, n);
                currPath.pop_back(); // backtrack
            }
        }
    }
};
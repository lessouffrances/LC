





// Time: 
// Space:
class Solution 
{
    public:
    string getHappyString(int n, int k) 
    {
        // get all happy strings
        dfs(n, "");
        sort(happyStrings.begin(), happyStrings.end());
        return happyStrings.size() >= k ? happyStrings[k-1] : "";
    }
    private:
    vector<string> happyStrings;
    void dfs(int n, string currPath)
    {
        if (currPath.length() == n) {
            happyStrings.push_back(currPath);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (currPath.empty() || ch != currPath.back()) {
                currPath += ch;
                dfs(n, currPath);
                currPath.pop_back();
            }
        }
    }
};
class Solution 
{
    public:
    int depthSum(vector<NestedInteger>& nestedList) 
    {
        return dfs(nestedList, 1);
    }

    private:
    int dfs(vector<NestedInteger>& nestedList, int depth)
    {
        int total = 0;
        for (NestedInteger ni : nestedList) {
            if (ni.isInteger()) {
                total += ni.getInteger() * depth;
            } else {
                total += dfs(ni.getList(), depth+1);
            }
        }
        return total;
    }
};
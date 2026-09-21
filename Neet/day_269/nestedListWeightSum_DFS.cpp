

class Solution 
{
    public:
    int depthSum(vector<NestedInteger>& nestedList) 
    {
        return dfs(1, nestedList);
    }

    private:
    int dfs(int depth, vector<NestedInteger>& nestedList)
    {
        int weightedSum = 0;

        for (auto& ni : nestedList) {
            if (ni.isInteger()) {
                weightedSum += depth * ni.getInteger();
            } else {
                weightedSum += dfs(depth+1, ni.getList());
            }
        }
        return weightedSum;
    }
};
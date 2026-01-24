class Solution 
{
    public:
    int depthSumInverse(vector<NestedInteger>& nestedList) 
    {
        queue<NestedInteger> q;
        for (auto& ni : nestedList) {
            q.push(ni);
        }

        int weighted = 0, unweighted = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                auto top = q.front();
                q.pop();

                if (top.isInteger()) {
                    unweighted += top.getInteger();
                }
                if (!top.isInteger()) {
                    for (auto& ni : top.getList()) {
                        q.push(ni);
                    }
                }
            }
            weighted += unweighted;
        }
        return weighted;
    }
};
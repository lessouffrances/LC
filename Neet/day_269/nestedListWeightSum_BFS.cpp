
class Solution 
{
    public:
    int depthSum(vector<NestedInteger>& nestedList) 
    {    
        queue<NestedInteger> q;
        // seed all the ni on the first depth
        for (auto& ni : nestedList) {
            q.push(ni);
        }

        int depth = 1;
        int weightedSum = 0;
        while (!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                auto currNi = q.front(); q.pop();

                if (currNi.isInteger()) {
                    weightedSum += depth * currNi.getInteger();
                } else {
                    for (auto& next : currNi.getList()) {
                        q.push(next);
                    }
                }
            }
            depth++;
        }
        return weightedSum;
    }
};
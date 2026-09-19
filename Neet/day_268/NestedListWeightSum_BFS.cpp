class Solution 
{
    public:
    int depthSum(vector<NestedInteger>& nestedList) 
    {
        queue<NestedInteger> q;
        
        for (NestedInteger ni : nestedList) {
            q.push(ni);
        }

        int depth = 1;
        int total = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i=0; i<sz; i++) {
                auto currNI = q.front(); q.pop();
                if (currNI.isInteger()) {
                    total += currNI.getInteger() * depth;
                } else {
                    for (auto& nextNI : currNI.getList()) q.push(nextNI);
                }
            }
            depth++;
        }
        return total;
    }
};
class Solution 
{
    public:
    int depthSum(vector<NestedInteger>& nestedList) 
    {
        if (nestedList.empty()) return 0;

        queue<NestedInteger> q;
        // push all first layer NI onto q
        for (auto& ni : nestedList) {
            q.push(ni);
        }
        
        int sum = 0;
        int layer = 1;
        while (!q.empty()) {
            int size = q.size();

            for (int i=0; i<size; i++) {
                auto ni = q.front();
                q.pop();
                if (ni.isInteger()) {
                    sum += layer * ni.getInteger();
                } else {
                    for (auto& nextNI : ni.getList()) {
                        q.push(nextNI);
                    }
                }
            }

            layer++;
        }
        return sum;
    }
};
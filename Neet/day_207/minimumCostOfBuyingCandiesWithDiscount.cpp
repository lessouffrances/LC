class Solution 
{
    public:
    int minimumCost(vector<int>& cost) 
    {
        if (cost.empty()) return 0;

        sort(cost.rbegin(), cost.rend());
        int n = cost.size();
        int totalCost = 0;

        for (int i=0; i<n; i++) {
            if ((i+1) % 3 == 0) continue; // because this one is free
            totalCost += cost[i];
        }
        return totalCost;
    }
};
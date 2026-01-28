class Solution 
{
    public:
    Solution(vector<int>& w)
    {
        totalSum = 0;
        for (int weight : w) {
            totalSum += weight;
            prefixSum.push_back(totalSum);
        }
    }

    int pickIndex() 
    {
        int target = rand() % totalSum;
        return upper_bound(prefixSum.begin(), prefixSum.end(), target) - prefixSum.begin();
    }
    private:
    vector<int> prefixSum;
    int totalSum;
};

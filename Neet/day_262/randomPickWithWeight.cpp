class Solution 
{
    public:
    Solution(vector<int>& w) 
    {
        for (int& weight : w) {
            currSum += weight;
            prefixSum.push_back(currSum);
        }
    }
    
    int pickIndex() 
    {
        int randomTarget = rand() % currSum; // pick a random weight inside the sum of weights
        // upper_bound returns the first idx whose element is > randomTarget
        int randomIdx = upper_bound(prefixSum.begin(), prefixSum.end(), randomTarget) - prefixSum.begin();
        return randomIdx;
    }

    private:
    vector<int> prefixSum;
    int currSum = 0;
};
    
    
class Solution 
{
    public:
    Solution(vector<int>& w)
    {
        for (int i=0; i<w.size(); i++) {
            currSum += w[i];
            prefixSum.push_back(currSum);
        }
    }
    int pickIndex() 
    {
        int randomTarget = rand() % currSum;
        int randomIdx = upper_bound(prefixSum.begin(), prefixSum.end(), randomTarget) - prefixSum.begin();
        return randomIdx;
    }
    private:
    vector<int> prefixSum;
    int currSum = 0;
};
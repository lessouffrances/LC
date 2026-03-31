




class Solution 
{
    public:
    Solution(vector<int>& w)
    {
        currSum = 0;
        for (int weight : w) {
            currSum += weight;
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
    int currSum;
};
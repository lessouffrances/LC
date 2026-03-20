
// Time: O(N)
// Space: O(N)

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
        int randomTarget = rand() % totalSum;
        // upper_bound method is O(log N)
        int randomIdx = upper_bound(prefixSum.begin(), prefixSum.end(), randomTarget) - prefixSum.begin();
        return randomIdx;
    }
    private:
    vector<int> prefixSum;
    int totalSum;
};
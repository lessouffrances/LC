class Solution 
{
    public:
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (totalSum % 3 != 0) return false;
        int sumOfPartitioned = totalSum / 3;

        int count = 0;
        int currSum = 0;
        for (int i=0; i<n; i++) {
            currSum += arr[i];
            if (currSum == sumOfPartitioned) {
                count++;
                currSum = 0;
            }
        }

        return count == 3;
    }
};
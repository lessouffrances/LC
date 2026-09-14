class Solution 
{
    public:
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if (totalSum % 3 != 0) return false;

        // then it is possible
        int sumOfPartitioned = totalSum / 3;
        // check
        int currSum = 0;
        int count = 0;
        for (int i=0; i<n; i++) {
            currSum += arr[i];
            if (currSum == sumOfPartitioned) {
                count++;
                currSum = 0; // reset
                // if count == 2 and still elements left, then true
                if (count == 2 && i < n-1) return true;
            };
        }
        return false;
    }
};
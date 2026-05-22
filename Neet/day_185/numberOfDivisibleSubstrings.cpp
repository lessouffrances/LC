// T: O(N)
// S: O(N)
class Solution 
{
    public:
    int countDivisibleSubstrings(string word) 
    {
        unordered_map<char, int> chToVals {
            {'a', 1}, {'b', 1}, 
            {'c', 2}, {'d', 2}, {'e', 2},
            {'f', 3}, {'g', 3}, {'h', 3},
            {'i', 4}, {'j', 4}, {'k', 4},
            {'l', 5}, {'m', 5}, {'n', 5},
            {'o', 6}, {'p', 6}, {'q', 6},
            {'r', 7}, {'s', 7}, {'t', 7},
            {'u', 8}, {'v', 8}, {'w', 8},
            {'x', 9}, {'y', 9}, {'z', 9}
        };

        // construct the prefixSum array
        int n = word.length();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = chToVals[word[0]];
        for (int i=1; i<n; i++) {
            prefixSum[i] = prefixSum[i-1]+chToVals[word[i]];
        }

        int count = 0;
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                int currSum = i>0 ? prefixSum[j]-prefixSum[i-1] : prefixSum[j];
                int currLen = j-i+1;
                if (currSum % currLen == 0) count++;
            }
        }
        return count;
    }
};
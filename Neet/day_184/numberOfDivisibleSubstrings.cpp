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

        int n = word.length();
        int count = 0;
        for (int i=0; i<n; i++) {
            int currSum = 0;
            for (int j=i; j<n; j++) {
                currSum += chToVals[word[j]];
                int currLen = j-i+1;
                if (currSum % currLen == 0) count++;
            }
        }
        return count;
    }
};
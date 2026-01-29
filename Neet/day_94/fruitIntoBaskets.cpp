class Solution 
{
    public:
    int totalFruit(vector<int>& fruits) 
    {
        if (fruits.empty()) return 0;
        unordered_map<int, int> windowCounter;
        int left = 0;
        int n = fruits.size();
        int maxLen = INT_MIN;

        for (int right=0; right<n; right++) {
            windowCounter[fruits[right]]++;

            while (windowCounter.size() > 2) {
                windowCounter[fruits[left]]--;
                if (windowCounter[fruits[left]] == 0) {
                    windowCounter.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
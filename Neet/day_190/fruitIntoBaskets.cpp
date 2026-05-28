class Solution 
{
    public:
    int totalFruit(vector<int>& fruits) 
    {
        if (fruits.empty()) return 0;

        unordered_map<int, int> windowCounter;
        int maxAmountOfFruits = 0;
        int left = 0;
        int n = fruits.size();
        for (int right=0; right<n; right++) {
            windowCounter[fruits[right]]++;
            while (windowCounter.size() > 2) {
                windowCounter[fruits[left]]--;
                if (windowCounter[fruits[left]] == 0) {
                    windowCounter.erase(fruits[left]);
                }
                left++;
            }
            maxAmountOfFruits = max(maxAmountOfFruits, right-left+1);
        }
        return maxAmountOfFruits;
    }
};
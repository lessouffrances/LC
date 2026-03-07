

//longest subarray that has only 2 distinct elements
// [3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4], exp = 5
// l
//              r
// maxLen = 4
class Solution 
{
    public:
    int totalFruit(vector<int>& fruits) 
    {
        if (fruits.empty()) return 0;

        int left = 0;
        unordered_map<int, int> fruitCounter;
        int maxLen = 0; // numOfFruits
        for (int right=0; right<fruits.size(); right++) {
            fruitCounter[fruits[right]]++;

            while (fruitCounter.size() > 2) {
                fruitCounter[fruits[left]]--;
                if (fruitCounter[fruits[left]] == 0) {
                    fruitCounter.erase(fruits[left]);
                }
                left++;
            }

            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};
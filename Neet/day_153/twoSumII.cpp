


// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        if (numbers.size() == 0) return {-1, -1};

        int left = 0, right = numbers.size()-1;
        while (left < right) {
            int twoSum = numbers[left]+numbers[right];
            if (twoSum == target) return {left+1, right+1};
            if (twoSum > target) {
                right--;
            } else {
                left++;
            }
        }
        return {-1, -1};
    }
};
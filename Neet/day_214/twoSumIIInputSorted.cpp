class Solution 
{
    public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        if (numbers.empty()) return {};
        int n = numbers.size();

        int left = 0, right = n-1;
        while (left < right) {
            int sumOfTwo = numbers[left]+numbers[right];
            if (sumOfTwo == target) return {left+1, right+1};
            
            if (sumOfTwo < target) {
                left++;
            } else {
                right--;
            }
        }
        return {-1, -1};
    }
};
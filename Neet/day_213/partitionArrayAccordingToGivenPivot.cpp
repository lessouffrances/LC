class Solution 
{
    public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        if (nums.empty()) return {};

        vector<int> lessThan;
        vector<int> greaterThan;
        vector<int> equals;

        for (int& num : nums) {
            if (num < pivot) {
                lessThan.push_back(num);
            } else if (num > pivot) {
                greaterThan.push_back(num);
            } else {
                equals.push_back(num);
            }
        }

        lessThan.insert(lessThan.end(), equals.begin(), equals.end());
        lessThan.insert(lessThan.end(), greaterThan.begin(), greaterThan.end());
        return lessThan;
    }
};
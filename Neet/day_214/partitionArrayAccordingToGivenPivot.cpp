class Solution 
{
    public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        vector<int> lessThan;
        vector<int> greaterThan;
        vector<int> equalsTo;

        for (int i=0; i<n; i++) {
            if (nums[i] > pivot) {
                greaterThan.push_back(nums[i]);
            } else if (nums[i] < pivot) {
                lessThan.push_back(nums[i]);
            } else {
                equalsTo.push_back(nums[i]);
            }
        }

        lessThan.insert(lessThan.end(), equalsTo.begin(), equalsTo.end());
        lessThan.insert(lessThan.end(), greaterThan.begin(), greaterThan.end());
        return lessThan;
    }
};
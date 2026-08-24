class Solution 
{
    public:
    vector<int> sortArray(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        if (nums.size() == 1) return nums;

        int n = nums.size();
        int mid = (n-1) / 2;
        vector<int> left = vector<int>(nums.begin(), nums.begin()+mid+1);
        vector<int> right = vector<int>(nums.begin()+mid+1, nums.end());
        left = sortArray(left);
        right = sortArray(right);
        return merge(left, right);
    }

    private:
    vector<int> merge(vector<int>& left, vector<int>& right)
    {
        vector<int> res;
        int i = 0, j = 0;
        int m = left.size(), n = right.size();
        while (i < m && j < n) {
            if (left[i] < right[j]) {
                res.push_back(left[i]);
                i++;
            } else {
                res.push_back(right[j]);
                j++;
            }
        }

        while (i < m) {
            res.push_back(left[i]);
            i++;
        }
        while (j < n) {
            res.push_back(right[j]);
            j++;
        }
        return res;
    }
};
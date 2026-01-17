class Solution 
{
    public:
    vector<int> sortArray(vector<int>& nums) 
    {
        if (nums.size() <= 1) return nums;

        int mid = (int) nums.size() / 2;
        vector<int> leftHalf = vector<int>(nums.begin(), nums.begin()+mid);
        vector<int> rightHalf = vector<int>(nums.begin()+mid, nums.end());

        vector<int> leftSorted = sortArray(leftHalf);
        vector<int> rightSorted = sortArray(rightHalf);

        return merge(leftSorted, rightSorted);
    }

    private:
    vector<int> merge(vector<int>& left, vector<int>& right)
    {
        vector<int> res;
        int i = 0;
        int j = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                res.push_back(left[i]);
                i++;
            } else {
                res.push_back(right[j]);
                j++;
            }
        }

        while (i < left.size()) {
            res.push_back(left[i]);
            i++;
        }

        while (j < right.size()) {
            res.push_back(right[j]);
            j++;
        }
        return res;
    }
};
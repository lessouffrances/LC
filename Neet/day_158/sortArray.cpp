



class Solution 
{
    public:
    vector<int> sortArray(vector<int>& nums)
    {
        if (nums.empty()) return {};
        if (nums.size() == 1) return nums;

        int l = 0;
        int r = nums.size()-1;
        int mid = l + (r - l) / 2;
        vector<int> leftHalf(nums.begin(), nums.begin()+mid+1);
        vector<int> rightHalf(nums.begin()+mid+1, nums.end());

        leftHalf = sortArray(leftHalf);
        rightHalf = sortArray(rightHalf);

        return merge(leftHalf, rightHalf);
    }

    private:
    vector<int> merge(vector<int>& left, vector<int>& right) 
    {
        vector<int> res;
        int i=0, j=0;

        while (i<left.size() && j<right.size()) {
            if (left[i] < right[j]) {
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
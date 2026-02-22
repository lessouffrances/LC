class Solution 
{
    public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n = nums.size();
        res.assign(n, 0);

        vector<pair<int, int>> arr(n);
        for (int i=0; i<n; i++) {
            arr[i] = {nums[i], i};
        }

        mergeSort(arr, 0, n);
        return res;
    }
    private:
    vector<int> res;

    void merge(vector<pair<int, int>>& arr, int left, int mid, int right)
    {
        vector<pair<int, int>> temp;
        int i = left, j = mid;

        while (i < mid && j < right) {
            if (arr[i].first <= arr[j].first) {
                // all elements from [mid, j) are smaller than arr[i]
                res[arr[i].second] += (j-mid);
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i < mid) {
            res[arr[i].second] += (j-mid);
            temp.push_back(arr[i]);
            i++;
        }
        while (j < right) {
            temp.push_back(arr[j]);
            j++;
        }
        copy(temp.begin(), temp.end(), arr.begin()+left);
    }

    void mergeSort(vector<pair<int, int>>& arr, int left, int right)
    {
        if (right - left <= 1) return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);
        merge(arr, left, mid, right);
    }
};
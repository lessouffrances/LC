

//               i
// leftHalf = [1,3,4,6]   
//                                    j
//                     rightHalf = [2,4,6,10]
// merged = [1,2,3]

class Solution 
{
    public:
    // the res contains [2, 1, 1, 3], 
    // headcount of smaller number that are to the right
    vector<int> countSmaller(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int n = nums.size();

        res.assign(n, 0);

        vector<pair<int, int>> arr; // stores the {nums[i], i} of original nums
        for (int i=0; i<n; i++) {
            arr.push_back( {nums[i], i} );
        }

        mergeSort(arr, 0, n);
        return res;
    }
    private: 
    // the way we leverage the mergeSort makes it necessary to put the res as class members
    vector<int> res;

    void merge(vector<pair<int, int>>& arr, int left, int mid, int right) {
        // write to a new temp, avoid to corrupt the original arr
        vector<pair<int, int>> temp;

        int i = left, j = mid;
        while (i<mid && j<right) {
            if (arr[i].first <= arr[j].first) {
                // the numbers between mid to j are smaller than nums[i]
                // // this is a `side effect` of merge 
                res[arr[i].second] += (j-mid);
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while (i<mid) {
            res[arr[i].second] += (j-mid);
            temp.push_back(arr[i]);
            i++;
        }
        while (j<right) {
            temp.push_back(arr[j]);
            j++;
        }
        copy(temp.begin(), temp.end(), arr.begin()+left);
    }

    void mergeSort(vector<pair<int, int>>& arr, int left, int right) 
    {
        // like the recursion func always have a base case
        if (right - left <= 1) return;
        int mid = left + (right-left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);
        merge(arr, left, mid, right);
    }
};

        
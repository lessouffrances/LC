

// Time: O(N logN)
// Space: O(1)
class Solution 
{
    public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        if (arr.empty()) return false;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for (int i=1; i<n-1; i++) {
            if (arr[i]-arr[i-1] != arr[i+1]-arr[i]) return false;
        }
        return true;
    }
};
class Solution 
{
    public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        set<int> sums;
        for (int start=0; start<arr.size(); start++) {
            for (int end=arr.size(); end>start; end--) {
                int currSum = accumulate(arr.begin()+start, arr.begin()+end, 0);
                sums.insert(currSum);
            }
        }
        return sums.size();
    }
};

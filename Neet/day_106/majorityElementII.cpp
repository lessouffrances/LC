








class Solution 
{
    public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 0;

        for (int& num : nums) {
            if (num == candidate1) {
                count1++;
            } else if (num == candidate2) {
                count2++;
            } else if (count1 == 0) {
                count1 = 1;
                candidate1 = num;
            } else if (count2 == 0) {
                count2 = 1;
                candidate2 = num;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;
        for (int& num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> res;
        if (count1 > nums.size() / 3) res.push_back(candidate1);
        if (count2 > nums.size() / 3) res.push_back(candidate2);
        
        return res;
    }
};
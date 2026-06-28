// nums = [2,0,2,1,1,0]
// counter: [2, 2, 2]
//           idx
class Solution 
{
    public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>counter(3, 0);
        for (int& num : nums) {
            counter[num-0]++;
        }

        int j = 0;
        for (int i=0; i<counter.size(); i++) {
            while (counter[i] > 0) {
                nums[j] = i;
                j++;
                counter[i]--;
            }
        }
    }
};
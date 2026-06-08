class Solution 
{
    public:
        void sortColors(vector<int>& nums) 
        {
            int n = nums.size();
            vector<int> counter(3, 0);

            for (int i=0; i<n; i++) {
                if (nums[i] == 0) {
                    counter[0]++;
                } else if (nums[i] == 1) {
                    counter[1]++;
                } else if (nums[i] == 2) {
                    counter[2]++;
                }
            }

            for (int i=0; i<n; i++) {
                if (counter[0] > 0) {
                    nums[i] = 0;
                    counter[0]--;
                    continue;
                } else if (counter[1] > 0) {
                    nums[i] = 1;
                    counter[1]--;
                    continue;
                } else {
                    nums[i] = 2;
                    counter[2]--;
                    continue;
                }
            }
        }
    };
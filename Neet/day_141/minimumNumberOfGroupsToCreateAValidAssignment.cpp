


class Solution 
{
    public:
    int minGroupsForValidAssignment(vector<int>& nums) 
    {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int minFreq = INT_MAX;
        for (auto& [num, count] : freq) {
            minFreq = min(count, minFreq);
        }

        for (int groupSize = minFreq; groupSize >= 1; groupSize--) {
            int totalGroups = 0;
            bool isValidAssignment = true;

            for (auto& [value, count] : freq) {
                if (count / groupSize < count % groupSize) {
                    isValidAssignment = false;
                    break;
                }

                totalGroups += (count + groupSize) / (groupSize + 1);

            }
            if (isValidAssignment) return totalGroups;
        }
        return 0;
    }
};
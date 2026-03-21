class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        // Count the frequency of each number in the array
        unordered_map<int, int> frequency;
        for (int num : nums) {
            frequency[num]++;
        }
      
        // Find the minimum frequency among all numbers
        // This will be our starting point for group size
        int minFrequency = INT_MAX;
        for (auto& [value, count] : frequency) {
            minFrequency = min(minFrequency, count);
        }
      
        // Try different group sizes starting from minFrequency down to 1
        // We want groups of size k or k+1
        for (int groupSize = minFrequency; groupSize >= 1; --groupSize) {
            int totalGroups = 0;
            bool isValidAssignment = true;
          
            // Check if current group size works for all frequencies
            for (auto& [value, count] : frequency) {
                // For a valid assignment with group sizes k and k+1:
                // We need at least as many groups of size k+1 as groups of size k
                // This translates to: count/groupSize >= count%groupSize
                if (count / groupSize < count % groupSize) {
                    isValidAssignment = false;
                    break;
                }
              
                // Calculate minimum number of groups needed for this frequency
                // Using groups of size groupSize or groupSize+1
                totalGroups += (count + groupSize) / (groupSize + 1);
            }
          
            // If we found a valid assignment, return the total number of groups
            if (isValidAssignment) {
                return totalGroups;
            }
        }
      
        // This should never be reached given the problem constraints
        return 0;
    }
};
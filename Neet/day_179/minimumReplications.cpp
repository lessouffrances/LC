// Problem Statement: Minimum Replications Base Segment
// Context:
// In Amazon's distributed storage network, 
// certain critical data segments represented as a string missingData 
// are unavailable due to synchronization issues.
// To restore them, the system starts with an empty string generatedData 
// and selects a baseSegment of length segmentSize. The following process then unfolds:

// The replication service generates a copy of baseSegment.
// Appends this copy to generatedData.
// Repeats steps 1–2 until the frequency of all characters in generatedData meets or exceeds their count in missingData.

// Given missingData and an integer segmentSize, find the baseSegment that requires the fewest number of replications 
// to satisfy this condition. If multiple baseSegments meet this requirement, return the lexicographically smallest one. 
// If no such segment exists, return "-1".

// Example 1:
// segmentSize = 2, missingData = "aavvavv"
// 'a' appears 3 times, 'v' appears 4 times
// baseSegment = "va" needs 4 copies to cover both
// baseSegment = "av" needs 4 copies as well → tie, pick lexicographically smaller → "av"

// Example 2 (Sample Case 0):
// segmentSize = 4, missingData = "abacbca"
// 'a' appears 3 times, 'b' and 'c' appear 2 times each
// baseSegment = "aabc" needs 2 copies → covers 'a'×2, 'b'×1, 'c'×1 per copy 
// → after 2 copies: 'a'×4 ≥ 3, 'b'×2 ≥ 2, 'c'×2 ≥ 2 ✓
// Output: "aabc"

// Function Description:
// string getBaseSegment(int segmentSize, string missingData)
// Returns: the lexicographically smallest baseSegment of length segmentSize whose 
// replications satisfy the requirements of missingData, or "-1" if none exists.

// Constraints:
// 1 ≤ segmentSize ≤ 2×10⁵
// 1 ≤ |missingData| ≤ 2×10⁵
// missingData only contains lowercase English letters 'a' to 'z'


class Solution
{
    public:
    string getBaseSegment(int segmentSize, const string& missingData)
    {
        vector<int> freq(26, 0);
        int maxFreq = 0;

        // Count frequency of each character
        for (char ch : missingData)
        {
            freq[ch - 'a']++;
            maxFreq = max(maxFreq, freq[ch - 'a']);
        }

        // Binary search minimum number of replications
        int lo = 1, hi = maxFreq;
        int ansK = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (isFeasible(mid, freq, segmentSize))
            {
                ansK = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }

        // No valid base segment
        if (ansK == -1)
        {
            return "-1";
        }

        // Build lexicographically smallest answer
        vector<int> need(26, 0);
        int used = 0;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                need[i] = (freq[i] + ansK - 1) / ansK;
                used += need[i];
            }
        }

        // Fill remaining positions with 'a'
        need[0] += (segmentSize - used);

        string result;

        for (int i = 0; i < 26; i++)
        {
            result.append(need[i], char('a' + i));
        }

        return result;
    }
    
    private:
    bool isFeasible(int k, const vector<int>& freq, int segmentSize)
    {
        long long needed = 0;

        for (int f : freq)
        {
            if (f > 0)
            {
                // Minimum count needed in one segment
                needed += (f + k - 1) / k;
            }
        }

        return needed <= segmentSize;
    }
};


//        i
// s = "0 0 1 1 0 0 1 1"

// prev = 0
// curr = 1


// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    int countBinarySubstrings(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();

        int prev = 0, curr = 1, res = 0;

        // note the i starts at 1
        for (int i=1; i<n; i++) {
            if (s[i] == s[i-1]) {
                curr++;
            } else {
                // finalize the prev group
                res += min(curr, prev);
                prev = curr;
                curr = 1;
            }
        }

        // handle the last pair
        res += min(curr, prev);
        return res;
    }
};
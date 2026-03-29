


// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    int numberOfSubstrings(string s) 
    {
        vector<int> counter(3, 0);

        int left = 0;
        int res = 0;
        int n = s.length();

        for (int right=0; right<n; right++) {
            counter[s[right]-'a']++;
            // when the prefix contains all 3 chars
            while (counter[0] && counter[1] && counter[2]) {
                res += n - right;
                counter[s[left]-'a']--;
                left++;
            }
        }
        return res;
    }
};



// Time: O(N)
// Space: O(1)
class Solution 
{
    public:
    int numberOfSubstrings(string s) 
    {
        vector<int> counter(3, 0);

        int left = 0, res = 0;
        int n = s.length();

        for (int right=0; right<n; right++) {
            counter[s[right]-'a']++;

            while (counter[0] && counter[1] && counter[2]) {
                res += n - right; // all substr with portion s[left, right]
                counter[s[left]-'a']--;
                left++;
            }
        }
        return res;
    }
};
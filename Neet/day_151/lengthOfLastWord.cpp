
// Time: O(N)
// Space: O(1)

class Solution 
{
    public:
    int lengthOfLastWord(string s) 
    {
        stringstream ss(s);
        string token;
        string last;
        while (getline(ss, token, ' ')) {
            if (!token.empty()) {
                last = token;
            }
        }
        return last.length();
    }
};
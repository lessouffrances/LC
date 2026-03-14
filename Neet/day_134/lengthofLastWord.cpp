class Solution 
{
    public:
    int lengthOfLastWord(string s) 
    {
        if (s.length() == 0) return 0;

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
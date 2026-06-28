class Solution 
{
    public:
    char processStr(string s, long long k) 
    {
        string res = processStrHelper(s);
        if (k < 1 || k > res.length()) return '.';
        return *(res.begin()+k);
    }

    private:
    string processStrHelper(string s)
    {
        string res = "";
        for (char ch : s) {
            if (ch == '*') {
                if (!res.empty()) res.pop_back();
            } else if (ch == '#') {
                res.insert(res.end(), res.begin(), res.end());
            } else if (ch == '%') {
                reverse(res.begin(), res.end());
            } else {
                res.push_back(ch);
            }
        }
        return res;
    }
};
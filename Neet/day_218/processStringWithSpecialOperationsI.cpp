// A '*' removes the last character from result, if it exists.
// A '#' duplicates the current result and appends it to itself.
// A '%' reverses the current result.
class Solution 
{
    public:
    string processStr(string s) 
    {
        return processStrHelper(s);
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
class Solution 
{
    public:
    string removeOuterParentheses(string s) 
    {
        string res = "";
        int depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) res += ch; // the sequence of these two lines of code matters
                depth++;
            } else {
                depth--;
                if (depth > 0) res += ch; // the sequence of these two lines of code matters
            }
        }

        return res;
    }
};
// for res, only include the parenthese whose depth is > 0
// be careful about where to add depth and where to subtract depth

class Solution 
{
    public:
    string removeOuterParentheses(string s) 
    {
        string res = "";
        int depth = 0;

        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) res += ch;
                depth++;
            } else {
                depth--;
                if (depth > 0) res += ch;
            }
        }
        return res;
    }
};





//      0 1 2 3 4
// s = "a b c d e", goal = "c d e a b"

class Solution 
{
    public:
    bool rotateString(string s, string goal) 
    {
       if (s.length() != goal.length()) return false;
       string doubleStr = s + s;
       return doubleStr.find(goal) != string::npos;
    }
};
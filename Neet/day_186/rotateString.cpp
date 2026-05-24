class Solution 
{
    public:
    bool rotateString(string s, string goal) 
    {
        if (s.length() != goal.length()) return false;
        string doubleS = s+s;
        if (doubleS.find(goal) != -1) {
            return true;
        }
        return false;
    }
};




class Solution 
{
    public:
    bool rotateString(string s, string goal) 
    {
        if (s.length() != goal.length()) return false;
        string copyS = s;
        s.insert(s.end(), copyS.begin(), copyS.end());

        if (s.find(goal) != -1) return true;
        else return false;
    }
};
class Solution 
{
    public:
    bool checkValidString(string s) 
    {
        if (s.length() == 0) return true;
        int n = s.length();
        stack<int> opens;
        stack<int> stars;

        for (int i=0; i<n; i++) {
            if (s[i] == ')') {
                if (!opens.empty()) {
                    opens.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }

             } else if (s[i] == '*') {
                stars.push(i);
            } else if (s[i] == '(') {
                opens.push(i);
            }
        }

        while (!opens.empty() && !stars.empty()) {
            if (opens.top() > stars.top()) return false;
            stars.pop(); opens.pop();
        }
        
        // because stars can be empty strings
        return opens.empty();
    }
};
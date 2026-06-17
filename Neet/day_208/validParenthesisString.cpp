class Solution 
{
    public:
    bool checkValidString(string s) 
    {
        stack<int> opens; // store indexes
        stack<int> stars; // store indexes
        int n = s.length();

        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                opens.push(i);
            } else if (s[i] == '*') {
                stars.push(i);
            } else {
                // exit
                if (!opens.empty()) {
                    open.pop();
                } else if (!stars.empty()) {
                    stars.pop();
                } else {
                    return false;
                }
            }
        }

        // see if the remainings match
        while (!open.empty() && !stars.empty()) {
            // '*(' can't be match
            if (open.top() > stars.top()) return false;
            opens.pop();
            stars.pop(); 
        }

        // since * can be empty "", only require open to be empty to be true
        return open.empty();
    }
};






class Solution 
{
    public:
    int longestValidParentheses(string s)
    {
        int n = s.length();

        int maxLen = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+2; j<=n; j+=2) {
                if (isValidParentheses(s.substr(i, j-i))) {
                    maxLen = max(maxLen, j-i);
                }
            }
        }
        return maxLen;

    }
    private:
    bool isValidParentheses(string s) 
    {
        if (s.length() == 0) return true;
        stack<char> deck;

        for (char ch : s) {
            if (ch == '(') {
                deck.push(ch);
            } else {
                if (!deck.empty()) {
                    deck.pop();
                } else {
                    return false;
                }
            }
        }
        return deck.empty();
    }
};
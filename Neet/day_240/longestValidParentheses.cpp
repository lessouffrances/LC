class Solution 
{
    public:
    int longestValidParentheses(string s) 
    {
        if (s.empty()) return 0;
        int n = s.length();
        stack<int> deck;
        deck.push(-1);
        int maxLen = 0;

        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                deck.push(i);
            } else {
                deck.pop();
                if (deck.empty()) {
                    deck.push(i);
                } else {
                    maxLen = max(maxLen, i-deck.top());
                }
            }
        }
        return maxLen;
    }
};
class Solution 
{
    public:
    int longestValidParentheses(string s) 
    {
        int n = s.length();
        stack<int> deck;
        deck.push(-1);

        int maxLen = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                deck.push(i);
            } else {
                deck.pop(); // pop the boundary
                if (deck.empty()) {
                    deck.push(i); // as new boundary
                } else {
                    maxLen = max(maxLen, i-deck.top());
                }
            }
        }
        return maxLen;
    }
};
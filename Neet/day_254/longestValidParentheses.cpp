
// s = "(()"
// s = ")()())"

class Solution 
{
    public:
    int longestValidParentheses(string s) 
    {
        if (s.length() == 0) return 0;

        stack<int> deck;
        deck.push(-1);
        int maxLen = 0;
        int n = s.length();

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

//      0 1 2 3 4 5
//                i
// s = ") ( ) ( ) )"

// deck = 5
// maxLen = 4

class Solution 
{
    public:
    int longestValidParentheses(string s) 
    {
        int n = s.length();
        stack<int> deck; // contain the index of '('
        deck.push(-1); // sentinel boundary

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



//          i
//  0 1 2 3 4
// "( ) ( ( )"
// deck = -1, 2, 
// maxLen = 2


class Solution 
{
    public:
    int longestValidParentheses(string s) 
    {
        stack<int> deck; // last unmatched idx
        deck.push(-1);
        int n = s.length();

        int maxLen = INT_MIN;
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
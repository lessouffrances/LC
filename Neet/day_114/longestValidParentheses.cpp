
//                 i
//       0 1 2 3 4 5 
// s = " ) ( ) ( ) ) ", exp = 4
// deck = 5 
// maxLen = 4
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
                deck.pop();
                if (deck.empty()){
                    deck.push(i);
                } else {
                    maxLen = max(maxLen, i-deck.top());
                }
            }
        }
        return maxLen;
    }
};
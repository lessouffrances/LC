








class Solution 
{
    public:
    int maxDepth(string s) 
    {
        if (s.length() == 0) return 0;

        // collect 
        string parentheses = "";
        for (char ch : s) {
            if (ch == '(' || ch == ')') 
            parentheses += ch;
        }

        int n = parentheses.length();
        stack<char> deck;
        int maxDepth = 0;
        for (int i=0; i<n; i++) {
            if (parentheses[i] == '(') {
                deck.push('(');
            } else {
                maxDepth = max(maxDepth, (int)deck.size());
                if (!deck.empty()) {
                    deck.pop();
                }
            }
        }
        
        return maxDepth;
    }
};
class Solution 
{
    public:
    int minLength(string s) 
    {
        if (s.length() == 0) return 0;
        stack<char> deck;

        for (char ch : s) {
            if (!deck.empty() && (
                (deck.top() == 'A' && ch == 'B') || (deck.top() == 'C' && ch == 'D')
            )) {
                deck.pop();
            } else {
                deck.push(ch);
            }
        }
        return deck.size();
    }
};
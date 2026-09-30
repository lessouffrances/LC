class Solution 
{
    public:
    int minAddToMakeValid(string s) 
    {
        if (s.length() == 0) return 0;

        stack<char> deck;
        int count = 0;
        for (char ch : s) {
            if (ch == ')') {
                if (!deck.empty()) {
                    deck.pop();
                } else {
                    count++;
                }
            } else {
                deck.push(ch);
            }
        }

        while (!deck.empty()) {
            count++;
            deck.pop();
        }
        return count;
    }
};
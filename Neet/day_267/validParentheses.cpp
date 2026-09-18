class Solution 
{
    public:
    bool isValid(string s) 
    {
        if (s.length() == 0) return false;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> deck;
        for (char ch : s) {
            if (closeToOpen.count(ch)) {
                if (!deck.empty() && closeToOpen[ch] == deck.top()) {
                    deck.pop();
                } else {
                    return false;
                }
            } else {
                deck.push(ch);
            }
        }
        return deck.empty();
    }
};
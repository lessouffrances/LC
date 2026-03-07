






class Solution 
{
    public:
    bool isValid(string s) 
    {
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        if (s.length() == 0) return false;

        stack<char> deck;
        for (char ch : s) {
            if (closeToOpen.count(ch)) {
                if (!deck.empty() && deck.top() == closeToOpen[ch]) {
                    deck.pop();
                } else {
                    return false;
                }
            } else {
                deck.push(ch);
            }
        }
        return deck.size() == 0;
    }
};
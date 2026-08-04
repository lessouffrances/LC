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
        return deck.empty();
    }
};
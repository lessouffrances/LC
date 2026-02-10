








class Solution 
{
    public:
    bool isValid(string s) 
    {
        unordered_map<char, char> closeToOpen = { {')', '('}, {']', '['}, {'}', '{'} };
        stack<char> deck;

        for (char ch : s) {
            // is close 
            if (closeToOpen.count(ch)) {
                if (!deck.empty() && deck.top() == closeToOpen[ch]) {
                    deck.pop();
                } else {
                    return false;
                }
            } else {
                // is open
                deck.push(ch);
            }
        }
        return deck.empty();
    }
};
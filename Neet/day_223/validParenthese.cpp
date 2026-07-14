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
                // exit
                if (!deck.empty() && deck.top() == closeToOpen[ch]) {
                    deck.pop();
                } else {
                    return false;
                }
            } else {
                // push the open one
                deck.push(ch);
            }
        }
        return deck.empty();
    }
};
class Solution 
{
    public:
    bool isValid(string s) 
    {
        stack<char> deck;
        unordered_map<char, char> closeToOpen = {{')', '('}, {'}', '{'}, {']', '['}};

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
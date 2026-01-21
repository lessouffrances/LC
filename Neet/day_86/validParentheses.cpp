class Solution 
{
    public:
    bool isValid(string s) 
    {
        if (s.empty()) return true;
        stack<char> deck;

        for (char ch : s) {
            if (closeToOpen.count(ch)) {
                // close parenthesis
                if (!deck.empty()) {
                    char pop = deck.top();
                    deck.pop();
                    if (pop != closeToOpen[ch]) return false;
                } else {
                    return false;
                }
            } else {
                // open parenthesis
                deck.push(ch);
            }
        }
        return deck.empty();
    }
    private:
    unordered_map<char, char> closeToOpen = {{')', '('}, {']', '['}, {'}', '{'}};
};
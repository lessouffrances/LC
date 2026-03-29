


// Time: O(N logN)
// Space: O(1)
class Solution 
{
    public:
    bool isValid(string s) 
    {
        if (s.length() == 0) return true;
        unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> deck;

        for (char ch : s) {
            // exit stack signal
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
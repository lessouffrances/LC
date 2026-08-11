class Solution 
{
    public:
    bool isValid(string s) 
    {
        int n = s.length();
        unordered_map<char, char> closeToOpen = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };

        stack<char> deck;
        for (int i=0; i<n; i++) {
            if (closeToOpen.count(s[i])) {
                if (!deck.empty() && deck.top() == closeToOpen[s[i]]) {
                    deck.pop();
                } else {
                    return false;
                }
            } else {
                deck.push(s[i]);
            }
        }
        return deck.empty();
    }
};
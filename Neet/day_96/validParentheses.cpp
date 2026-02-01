










// s = "()[]{}"




class Solution 
{
    public:
    bool isValid(string s) 
    {
        if (s.length() == 0) return false;
        int n = s.length();
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
    private:
    unordered_map<char, char> closeToOpen = { {')','('}, {'}','{'}, {']','['} };
};
 
// 1432219
// monotonic stack: some property/condition can be applied consistently
// want to have the least number after removing k digits
// want to remove digits that sit to the left and the digits should be as big as much
// deck = 1 2 1 9
// k = 3-1-1-1 = 0

class Solution 
{
    public:
    string removeKdigits(string num, int k) 
    {
        // obvious edge cases:
        if (k >= num.length()) return "0";
        if (k == 0) return num;

        string deck = ""; // use string as a stack
        for (char digit : num) {
            while (!deck.empty() && digit < deck.back() && k > 0) {
                deck.pop_back();
                k--;
            }
            deck.push_back(digit);
        }

        // if k not fully used, remove the remaining digits from the end
        while (!deck.empty() && k > 0) {
            deck.pop_back();
            k--;
        }

        // strip leading zeros
        // 001334
        int i = 0; 
        while (i < deck.length()-1 && deck[i] == '0') i++;
        deck = deck.substr(i);

        return deck.empty() ? "0" : deck;
    }
};
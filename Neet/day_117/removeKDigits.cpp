






// num = "10", k = 2
// deck = 

// num = "10200", k = 1
// deck = 0 2 0 0

// num = "1432219", k = 3
// deck = 1 2 1 9

class Solution 
{
    public:
    string removeKdigits(string num, int k) 
    {
        string deck; // use vector as stack for string types

        for (char ch : num) {
            while (k > 0 && !deck.empty() && deck.back() > ch) {
                deck.pop_back();
                k--;
            }
            deck.push_back(ch);
        }

        // let k reach 0
        while (k-- > 0) deck.pop_back();

        // skip leading 0s
        int start = 0;
        while (start < (int)deck.size()-1 && deck[start] == '0') start++;
        return deck.empty() ? "0" : deck.substr(start);
    }
};
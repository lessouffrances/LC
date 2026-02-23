






// num = "1 4 3 2 2 1 9", k = 0
// deck = 1 2 1 9

// if deck.top() > currNum
class Solution 
{
    public:
    string removeKdigits(string num, int k) 
    {
        string deck;
        int n = num.length();

        for (int i=0; i<n; i++) {
            while (!deck.empty() && deck.back() > num[i] && k > 0) {
                deck.pop_back();
                k--;
            }
            deck.push_back(num[i]);
        }

        // let k reach 0;
        while (k > 0 && !deck.empty()) {
            deck.pop_back();
            k--;
        }

        // skip leading zeros
        int start=0; 
        while (start < deck.size()-1 && deck[start] == '0') start++;
        return deck.empty() ? "0" : deck.substr(start);
    }
};
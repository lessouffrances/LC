


// num = "1432219", k = 3 [remove 4,3,2]
// deck = 1 2 1 9

// Time: O(N logN)
// Space: O(N)
class Solution 
{
    public:
    string removeKdigits(string num, int k) 
    {
        if (num.length() == 0 || k == 0) return num;

        string deck = "";
        for (char ch : num) {
            int number = ch - '0';

            while (!deck.empty() && number < (deck.back()-'0') && k > 0) {
                deck.pop_back();
                k--;
                continue;
            }
            deck.push_back(ch);
        }

        // let k reach 0 if not yet
        while (!deck.empty() && k > 0) {
            deck.pop_back();
            k--;
        }

        // ignore leading 0s
        int start = 0;
        while (start < deck.length()-1 && deck[start] == '0') {
            start++;
        }
        return deck.empty() ? "0" : deck.substr(start);
    }
};
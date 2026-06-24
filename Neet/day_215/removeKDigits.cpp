
// num = "1432219", k = 3
// deck = [1,

class Solution 
{
    public:
    string removeKdigits(string num, int k) 
    {
        if (num.length() == 0) return "";
        int n = num.size();

        string deck = "";
        for (int i=0; i<n; i++) {
            char ch = num[i];
            while (!deck.empty() && (ch-'0') < (deck.back()-'0') && k > 0) {
                // the smaller number should take the pos
                deck.pop_back();
                k--;
            }
            deck.push_back(ch);
        } 

        // why we popback?
        // because the stack is monotonically increasing
        // [1,2,3,4,5]
        // [1,2,3] is smaller than [3,4,5]
        while (!deck.empty() && k > 0) {
            deck.pop_back();
            k--;
        }

        // ignore leading zeros
        int start = 0;
        while (start < deck.length()-1 && deck[start] == '0') {
            start++;
        }
        return deck.empty() ? "0" : deck.substr(start);
    }
};
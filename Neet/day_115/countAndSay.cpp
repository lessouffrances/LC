




class Solution 
{
    public:
    string countAndSay(int n) 
    {
        string prevTerm = "1";
        for (int i=0; i<n-1; i++) {
            prevTerm = countAndSayHelper(prevTerm);
        }
        return prevTerm;
    }
    private:
    //                  i
    // "1 1 2 1 3 3 3 4"
    // deck = {4,1}
    // res = "21121133"
    string countAndSayHelper(const string& s)
    {
        if (s.length() == 0) return "";
        stack<pair<char, int>> deck;

        string res = "";
        for (char ch : s) {
            if (!deck.empty() && ch == deck.top().first) {
                deck.top().second++;
                continue;
            }
            if(!deck.empty()) {
                auto [ch, count] = deck.top();
                deck.pop();
                res += to_string(count) + ch;
            }
            deck.push( {ch, 1} );
        }
        if (!deck.empty()) {
            auto [ch, count] = deck.top();
            deck.pop();
            res += to_string(count) + ch;
        }
        return res;
    }
};
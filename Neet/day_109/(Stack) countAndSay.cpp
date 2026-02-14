class Solution 
{
    public:
    string countAndSay(int n) 
    {
        string prev = "1";
        for (int i=0; i<n-1; i++) {
            prev = countAndSayHelper(prev);
        }
        return prev;
    }
    private:
    //                                      i                        
    // "2  2  3  3  1  4  4  4  4  4  1  1"
    // {1,2}
    // "22231154"
    string countAndSayHelper(const string& s)
    {
        stack<pair<char, int>> deck;

        string res = "";
        for (char ch : s) {
            if (!deck.empty() && ch == deck.top().first) {
                deck.top().second++;
            } else if (!deck.empty()) {
                // write to res
                res += to_string(deck.top().second) + deck.top().first;
                deck.pop();
                deck.push( {ch, 1} );
            } else {
                deck.push( {ch, 1} );
            }
        }
        res += to_string(deck.top().second) + deck.top().first;
        return res;
    }
};
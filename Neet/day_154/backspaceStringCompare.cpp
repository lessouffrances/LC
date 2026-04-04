





class Solution 
{
    public:
    bool backspaceCompare(string s, string t) 
    {
        return consolidateString(s) == consolidateString(t);
    }

    private:
    string consolidateString(const string& s) 
    {
        string deck = "";

        for (char ch : s) {
            if (ch == '#') {
                if (!deck.empty()) deck.pop_back();
            } else {
                deck.push_back(ch);
            }
        }
        return deck;
    }
};
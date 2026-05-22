// T: O(N)
// S: O(N)

class Solution 
{
    public:
    // "y#fo##f"
    // "y#f#o##f"
    bool backspaceCompare(string s, string t) 
    {
        return processString(s) == processString(t);
    }
    private:
    string processString(const string& s) 
    {
        stack<char> deck;
        for (char ch : s) {
            if (ch == '#') {
                if (!deck.empty()) deck.pop();
            } else {
                deck.push(ch);
            }
        }

        string res = "";
        while (!deck.empty()) {
            res = deck.top() + res;
            deck.pop();
        }
        return res;
    }
};
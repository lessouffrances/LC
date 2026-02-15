







// s = "a b b a c a", output = "ca"
// deck = a b 

class Solution 
{
    public:
    string removeDuplicates(string s) 
    {
        if (s.length() == 0) return "";

        stack<char> deck; 
        for (char ch : s) {
            if (!deck.empty() && ch == deck.top()) {
                deck.pop();
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
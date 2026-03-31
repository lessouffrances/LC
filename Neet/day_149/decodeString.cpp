

// "2[abc]3[cd]ef"
// abcabccdcdcdef

class Solution 
{
    public:
    string decodeString(string s) 
    {
        if (s.length() == 0) return "";
        int n = s.length();

        stack<char> deck;

        for (int i=0; i<n; i++) {
            // signal for exit
            if (s[i] == ']') {
                string currStr = "";
                while (!deck.empty() && deck.top() != '[') {
                    currStr = deck.top() + currStr;
                    deck.pop();
                }

                // pop the [
                deck.pop();

                // get the scaler
                string scaler = "";
                while (!deck.empty() && isdigit(deck.top())) {
                    scaler = deck.top() + scaler;
                    deck.pop();
                }
                int scalerNum = stoi(scaler);

                string toPush = "";
                for (int i=0; i<scalerNum; i++) {
                    toPush += currStr;
                }

                // push sole char 
                for (char ch : toPush) {
                    deck.push(ch);
                }

            } else {
                deck.push(s[i]);
            }
        }

        // consolidate the stack
        string res = "";
        while (!deck.empty()) {
            res = deck.top() + res;
            deck.pop();
        }
        return res;
    }
};
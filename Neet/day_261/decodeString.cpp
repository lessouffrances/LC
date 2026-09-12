// s = "2[abc]3[cd]ef"
// s = "3[a2[c]]"
// deck = accaccacc

class Solution 
{
    public:
    string decodeString(string s) 
    {
        if (s.length() == 0) return "";

        stack<char> deck;
        // ] is an exit
        for (char ch : s) {
            if (ch == ']') {
                // exit stack
                string currStr = "";
                while (!deck.empty() && deck.top() != '[') {
                    currStr = deck.top() + currStr;
                    deck.pop();
                }

                // there should be a [ 
                deck.pop();
                string currNum = "";
                while (!deck.empty() && isdigit(deck.top())) {
                    currNum = deck.top() + currNum;
                    deck.pop();
                }

                int scaler = stoi(currNum);
                string toPush = "";
                for (int i=0; i<scaler; i++) {
                    toPush += currStr;
                }
                for (char ch : toPush) {
                    deck.push(ch);
                } 
            } else {
                // enter stack
                deck.push(ch);
            }
        }

        // consolidate stack
        string res = "";
        while (!deck.empty()) {
            res = deck.top() + res;
            deck.pop();
        }
        return res;
    }
};
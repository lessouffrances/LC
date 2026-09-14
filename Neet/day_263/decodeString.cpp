class Solution 
{
    public:
    string decodeString(string s) 
    {
        if (s.length() == 0) return "";

        stack<char> deck;
        int n = s.length();
        int i=0;
        while (i<n) {
            if (s[i] == ']') {
                // signal for exit stack
                // pop stack until the [ appears
                string currStr = "";
                while (!deck.empty() && deck.top() != '[') {
                    currStr = deck.top() + currStr;
                    deck.pop();
                }
                deck.pop(); // now pop the [

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
                // push to the stack
                deck.push(s[i]);
            }
            i++;
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
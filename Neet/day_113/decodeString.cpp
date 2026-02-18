







// s = " 2 [ a b c ] 3 [ c d ] e f "
// deck = abcabc cdcdcd ef
class Solution 
{
    public:
    string decodeString(string s) 
    {
        if (s.empty()) return "";

        stack<char> deck;
        int n = s.length();
        for (int i=0; i<n; i++) {
            if (s[i] == ']') {
                string currStr = "";
                while (!deck.empty() && deck.top() != '[') {
                    currStr = deck.top() + currStr;
                    deck.pop();
                }
                deck.pop(); // pop the [

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
                deck.push(s[i]);
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
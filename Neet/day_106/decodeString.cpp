


//                            i
// "2 [ a b c ] 3 [ c d ] e f"
// deck = abcabc cdcdcd e f


class Solution 
{
    public:
    string decodeString(string s) 
    {
        if (s.length() == 0) return "";

        stack<char> deck;
        for (char ch : s) {
            if (ch == ']') {
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

                int scaler = 1;
                if (!currNum.empty()) {
                    scaler = stoi(currNum);
                }
                
                string pushUp = "";
                for (int i=0; i<scaler; i++) {
                    pushUp += currStr;
                }
                for (char ch : pushUp) {
                    deck.push(ch);
                }

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
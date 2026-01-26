// s = "3+2*2"
// s = " 3/2 "
// s = " 3+5 / 2 "

// deck = [3+4]
// deck = [1]
// deck = [3+2]

class Solution 
{
    public:
    int calculate(string s) 
    {
        if (s.length() == 0) return 0;

        stack<int> deck;
        int i = 0;
        int n = s.length();

        while (i < n) {
            if (s[i] == '*' || s[i] == '/') {
                char op = s[i];
                // get the entire number after *
                string currNum = "";
                while (i+1 < n && isdigit(s[i+1])) {
                    i++;
                    currNum += s[i];
                }
                int currNum = stoi(currNum);
                int currRes = 0;
                if (op == '*') {
                    currRes = deck.top() * currNum;
                } else {
                    currRes = deck.top() / currNum;
                }
                deck.push(currRes); // int

            } else if (s[i] = ' ') {
                i++;
            } else {
                currNum= "";
                if (s[i] == '+' || s[i] == '-') {
                    op = s[i];
                    while (i+1 < n && isdigit(s[i+1])) {
                        i++;
                        currNum += s[i];
                    }
                    if (op == '+') {
                        currNum = stoi(currNum);
                    } else {
                        currNum = -stoi(currNum);
                    }
                } else {
                    currNum += s[i];
                    while (i+1 < n && isdigit(s[i+1])) {
                        i++;
                        currNum += s[i];
                    }
                    currNum = stoi(currNum);
                }
                deck.push(currNum); // int
            }

            i++;
        }

        // evaluate the final +/- expressions by sequence
        int res = 0;
        while (!deck.empty()) {
            res += deck.top();
            deck.pop();
        }
        return res;
    }
};
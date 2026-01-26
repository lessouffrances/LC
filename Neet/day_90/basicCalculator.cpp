class Solution 
{
    public:
    int calculate(string s) 
    {
        if (s.length() == 0) return 0;

        stack<int> deck;
        int n = s.length();

        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++; 
                continue;
            }

            if (s[i] == '*' || s[i] == '/') {
                char op = s[i];
                i++;

                // spaces are there after an op
                while (i < n && s[i] == ' ') i++;

                // get the entire number after the op
                string currStr = "";
                while (i < n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }
                if (subStr.empty()) return 0;
                int currNum = stoi(currStr);

                // pop the prev number on the stack and do the op
                int prev = deck.top();
                deck.pop();
                int currRes = (op == '*') ? prev * currNum : prev / currNum;
                deck.push(currRes);

            } else if (s[i] == '+' || s[i] == '-') {
                char op = s[i];
                i++;

                // spaces are there after an op
                while (i < n && s[i] == ' ') i++;

                // get the entire number after the op
                string currStr = "";
                while (i < n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }
                if (subStr.empty()) return 0;
                int currNum = stoi(currStr);

                // push with the sign
                deck.push( (op == '+') ? currNum : -currNum );
            } else if (isdigit(s[i])) {
                // get the entire number 
                string currStr = "";
                while (i < n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }
                if (subStr.empty()) return 0;
                int currNum = stoi(currStr);
                deck.push(currNum);
            } else {
                i++;
            }
        }

        // evaluate the result
        int res = 0;
        while (!deck.empty()) {
            res += deck.top();
            deck.pop();
        }
        return res;
    }
};
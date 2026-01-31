class Solution 
{
    public:
    int calculate(string s) 
    {
        if (s.length() == 0) return 0;

        int i = 0;
        int n = s.length();
        stack<int> deck;

        while (i<n) {
            while (i<n && s[i] == ' ') {
                i++; 
            }

            if (s[i] == '*' || s[i] == '/') {
                char op = s[i];
                i++;

                // skip thru spaces after an op
                while (i<n && s[i] == ' ') {
                    i++; 
                }

                // get the entire number
                string currStr = "";
                while (i<n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }
                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);

                // pop the prev num on deck to do the op
                int prev = deck.top();
                deck.pop();
                int currRes = (op == '*') ? prev * currNum : prev / currNum;
                deck.push(currRes);

            } else if (s[i] == '+' || s[i] == '-') {
                char op = s[i];
                i++;

                // skip thru spaces after an op
                while (i<n && s[i] == ' ') {
                    i++; 
                }

                // get the entire number
                string currStr = "";
                while (i<n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }
                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);

                // push with the sign
                deck.push(  (op == '+') ? currNum : -currNum );
            } else if (isdigit(s[i])) {
                // get the entire number
                string currStr = "";
                while (i<n && isdigit(s[i])) {
                    currStr += s[i];
                    i++;
                }
                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);
                deck.push(currNum);

            } else {
                i++;
            }
        }

        // evaluate the result
        int res;
        while (!deck.empty()) {
            res += deck.top();
            deck.pop();
        }
        return res;
    }
};
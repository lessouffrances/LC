class Solution 
{
    public:
    int calculate(string s) 
    {
        if (s.length() == 0) return 0;
        int n = s.length();
        stack<int> deck;

        int i = 0;
        while (i<n) {
            // skip spaces
            while (i<n && s[i] == ' ') {
                i++;
            }

            // if op is * or /
            if (s[i] == '*' || s[i] == '/') {
                char op = s[i];
                i++;

                // skip spaces
                while (i<n && s[i] == ' ') {
                    i++;
                }

                // get the entire number after op
                string currStr = "";
                while (i<n && s[i] >= '0' && s[i] <= '9') {
                    currStr += s[i];
                    i++;
                }
                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);
                 
                // pop the number on top
                int prev = deck.top();
                deck.pop();

                // do the op and push the res
                deck.push( (op == '*') ? (prev * currNum) : (prev / currNum));

            } else if (s[i] == '+' || s[i] == '-') {
                char op = s[i];
                i++;

                // skip spaces
                while (i<n && s[i] == ' ') {
                    i++;
                }

                // get the entire number after op
                string currStr = "";
                while (i<n && s[i] >= '0' && s[i] <= '9') {
                    currStr += s[i];
                    i++;
                }
                if (currStr.empty()) return 0;
                int currNum = stoi(currStr);
                 
                // push the num with sign
                deck.push( (op == '+') ? (currNum) : (-currNum));

            } else if (s[i] >= '0' && s[i] <= '9') {
                // get the entire number after op
                string currStr = "";
                while (i<n && s[i] >= '0' && s[i] <= '9') {
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

        int res = 0;
        while (!deck.empty()) {
            res += deck.top();
            deck.pop();
        }

        return res;
    }
};
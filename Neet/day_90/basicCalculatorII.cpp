class Solution 
{
    public:
    int calculate(string s) 
    {
        if (s.length() == 0) return 0;

        int n = s.length();
        stack<string> deck;
        int i = 0;

        while (i < n) {

            if (s[i] == ')') {
                long long currNum = 0;  // Use long long
                while (!deck.empty() && deck.top() != "(") {
                    string top = deck.top();
                    deck.pop();
                    
                    if (top == "+" || top == "-") {
                        continue;
                    }
                    
                    currNum += stoll(top);  // Use stoll
                }

                deck.pop();  // pop the (
                
                if (!deck.empty() && (deck.top() == "+" || deck.top() == "-")) {
                    string sign = deck.top();
                    deck.pop();
                    if (sign == "-") {
                        currNum = -currNum;
                    }
                }
                
                deck.push(to_string(currNum));
                i++;

            } else if (s[i] == '+' || s[i] == '-') {
                char op = s[i];
                i++;

                while (i < n && s[i] == ' ') i++;
                
                if (i >= n || s[i] == '(') {
                    deck.push(string(1, op));
                    continue;
                }
                
                string currStr = "";
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    currStr += s[i];
                    i++;
                }
                
                if (currStr.empty()) continue;
                
                // Use long long for negation
                if (op == '+') {
                    deck.push(currStr);
                } else {
                    long long num = stoll(currStr);
                    deck.push(to_string(-num));
                }

            } else if (s[i] == ' ') {
                i++;
            } else if (s[i] == '('){
                deck.push("(");
                i++;
            } else if (s[i] >= '0' && s[i] <= '9') {
                string currStr = "";
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    currStr += s[i];
                    i++;
                }
                deck.push(currStr);

            } else {
                i++;
            }
        }

        // evaluate the result
        long long res = 0;  // Use long long
        while (!deck.empty()) {
            string top = deck.top();
            deck.pop();
            
            if (top == "+" || top == "-" || top == "(") {
                continue;
            }
            
            res += stoll(top);  // Use stoll
        }
        return (int)res;  // Cast back to int
    }
};
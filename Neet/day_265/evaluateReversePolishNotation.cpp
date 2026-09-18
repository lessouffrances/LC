// tokens = ["2","1","+","3","*"]
// deck = [9]

// tokens = ["4","13","5","/","+"]
// deck = [6]
// tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]

// rule keep push to the stack until the op appears,
// 
class Solution 
{
    public:
    int evalRPN(vector<string>& tokens) 
    {
        if (tokens.empty()) return 0;
        int n = tokens.size();

        stack<long long> deck;
        for (int i=0; i<n; i++) {

            if (tokens[i] == "+" || tokens[i] == "-" 
                || tokens[i] == "/" || tokens[i] == "*") {

                int num2 = deck.top(); deck.pop();
                int num1 = deck.top(); deck.pop();

                if (tokens[i] == "+") {
                    deck.push(num1 + num2);

                } else if (tokens[i] == "-") {
                    deck.push(num1 - num2);

                } else if (tokens[i] == "*") {
                    deck.push(num1 * num2);

                } else if (tokens[i] == "/") {
                    deck.push(num1 / num2);
                } 

            } else {
                deck.push( stoi(tokens[i]) );
            }
        }
        return (int)deck.top();
    }
};
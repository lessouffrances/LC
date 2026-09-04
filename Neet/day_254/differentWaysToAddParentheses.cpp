class Solution 
{
    public:
    vector<int> diffWaysToCompute(string expression) 
    {
        return solve(expression);
    }

    private:
    unordered_map<string, vector<int>> memo;
    vector<int> solve(const string& expr)
    {
        if (memo.count(expr)) return memo[expr];
        vector<int> res;
        bool isNumber = true;
        
        for (int i = 0; i < expr.length(); i++) {
            char ch = expr[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                isNumber = false;
                vector<int> leftResults = solve(expr.substr(0, i));
                vector<int> rightResults = solve(expr.substr(i + 1));
                
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (ch == '+') res.push_back(l + r);
                        else if (ch == '-') res.push_back(l - r);
                        else res.push_back(l * r);
                    }
                }
            }
        }
        
        if (isNumber) {
            res.push_back(stoi(expr));
        }
        memo[expr] = res;
        return res;
    }
};
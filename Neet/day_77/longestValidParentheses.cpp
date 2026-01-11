#include <stack>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
    public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // Base for length calculation
        int maxLen = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);  // New base
                } else {
                     maxLen = max(maxLen, i - st.top());
                }
            }
        }
        return maxLen;
    }
};

int main() {
    Solution solution = Solution();
    string test = "(()";
    string test_1 = ")()())";
    printf("%d\n", solution.longestValidParentheses(test_1));
}
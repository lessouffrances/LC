class Solution {
    public:
        string shortestPalindrome(string s) {
            STRING = s;
            int n = s.length();
            int mid = n / 2;

            for (int i=mid; i>=0; i--) {
                // Even-length center: check s[i] == s[i+1] before expanding
                if (STRING[i] == STRING[i+1]) {
                    auto [left, right] = expand(i, i+1);
                    if (left == -1) {
                        // Palindrome is anchored at index 0.
                        // Reverse the unmatched suffix and prepend it.
                        string toAdd = s.substr(right);
                        return string(toAdd.rbegin(), toAdd.rend())+s;
                    }
                }
    
                // Odd-length center: single character as center
                auto [left, right] = expand(i, i);
                if (left == -1) {
                    string toAdd = s.substr(right);
                    return string(toAdd.rbegin(), toAdd.rend()) + s;
                }
            }
    
            return s;
        }
    
    private:
        string STRING;
    
        // Expand outward from (left, right) while characters match.
        // Returns final (left, right) after expansion stops.
        // left == -1 means the palindrome is anchored at index 0.
        pair<int, int> expand(int left, int right) {
            int n = STRING.length();
            while (left >= 0 && right < n && STRING[left] == STRING[right]) {
                left--;
                right++;
            }
            return {left, right};
        }
    };
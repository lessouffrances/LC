class Solution 
{
    public:
    //  l           
    //                r
    // "I c e C r e A m"
    string reverseVowels(string s) 
    {
        int left = 0, right = s.length()-1;
        unordered_set<char> vowelsSet = {'a', 'e', 'i', 'o', 'u'};

        while (left < right) {
            while (left < right && !vowelsSet.count(tolower(s[left]))) {
                left++;
            }
            while (left < right && !vowelsSet.count(tolower(s[right]))) {
                right--;
            }
            if (s[left] != s[right]) {
                swap(s[left], s[right]);
            }
            left++;
            right--;
        }
        return s;
    }
};
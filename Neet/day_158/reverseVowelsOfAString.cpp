class Solution 
{
    public:
    string reverseVowels(string s) 
    {
        unordered_set<char> vowelSet = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        };

        if (s.length() == 0) return "";
        int left = 0, right = s.length()-1;

        while (left < right) {
            while (left < right && !vowelSet.count(s[left])) left++;
            while (left < right && !vowelSet.count(s[right])) right--;

            if (s[left] != s[right]) {
                swap(s[left], s[right]);
            }
            left++;
            right--;
        }
        return s;
    }
};
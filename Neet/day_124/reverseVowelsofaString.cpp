
//          i             
//                j
// s = "A c e C r e I m"

// a e i o u
// s = "A c e C r e I m"


//          i
//                j
// s = "l e o t c e d e"
// s = "l e o t c e d e"

class Solution 
{
    public:
    string reverseVowels(string s) 
    {
        int left = 0, right = s.length()-1;
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};

        while (left < right) {
            while (!vowelSet.count(tolower(s[left]))) {
                left++;
            }
            while (!vowelSet.count(tolower(s[right]))) {
                right--;
            }
            // once find:
            if (s[left] != s[right]) {
                swap(s[left], s[right]);
            }
            
            left++;
            right--;
        }
        return s;
    }
};
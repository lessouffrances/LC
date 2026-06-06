class Solution 
{
    public:
    int numberOfSpecialChars(string word) 
    {
        unordered_set<char> charSet(word.begin(), word.end());

        int count = 0;
        for (char ch='a'; ch<='z'; ch++) {
            if (charSet.count(ch) && charSet.count(ch-32)) count++;
        }
        return count;
    }
};
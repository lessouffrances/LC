class Solution 
{
    public:
    int numberOfSpecialChars(string word) 
    {
        unordered_set<char> letterSet(word.begin(), word.end());

        int count = 0;
        for (char ch : letterSet) {
            if (letterSet.count(ch-32)) count++;
        }
        return count;
    }
};

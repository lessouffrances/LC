class Solution 
{
    public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> jewelsChars;
        for (char ch : jewels) {
            jewelsChars.insert(ch);
        }

        int count = 0;
        for (char ch : stones) {
            if (jewelsChars.count(ch)) {
                count++;
            }
        }
        return count;
    }
};
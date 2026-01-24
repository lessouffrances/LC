class Solution 
{
    public:
    bool reorderedPowerOf2(int n) 
    {
        vector<int> nBits = getBitsVec(n);

        for (int i=0; i<30; i++) {
            if (getBitsVec(1 << i) == nBits) {
                return true;
            }
        }
        return false;
    }
    private:
    vector<int> getBitsVec(int n)
    {
        vector<int> bits(10, 0);
        while (n > 0) {
            bits[n % 10]++;
            n /= 10;
        }
        return bits;
    }
};
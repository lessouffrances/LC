class Solution 
{
    public:
    int bitwiseComplement(int n) 
    {
        if (n == 0) return 1;
        // get the bin of n 
        string bin = bitset<32>(n).to_string();

        // strip leading 0s
        auto iter = bin.find('1');
        string strippedBin = bin.substr(iter);

        // get the deci of full-len
        string binSum = string(strippedBin.length(), '1');
        int sum = stoi(binSum, nullptr, 2);

        // subtract
        return sum - n;
    }
};
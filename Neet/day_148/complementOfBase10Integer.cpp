



class Solution 
{
    public:
    int bitwiseComplement(int n) 
    {
        if (n == 0) return 1;
        // convert n to bin
        string bin = bitset<32>(n).to_string();

        // strip leading 0s
        auto iter = bin.find("1");
        string binary = bin.substr(iter);

        int len = binary.length();
        string sumBin = string(len, '1');

        // template: parsedSubject, parsedEndIter, base
        int sumDecimal = stoi(sumBin, nullptr, 2);
        return sumDecimal-n;
    }
};
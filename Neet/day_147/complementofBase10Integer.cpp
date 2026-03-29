


class Solution 
{
    public:
    int bitwiseComplement(int n) 
    {
        if (n == 0) return 1;
        // convert n into binary string
        string binary = bitset<32>(n).to_string();

        // strip leading 0s
        auto iter = binary.find("1");
        string binaryFinal = binary.substr(iter);

        int len = binaryFinal.length();
        string binarySum = string(len, '1');
        int decimalSum = stoi(binarySum, nullptr, 2);
        return decimalSum - n;
    }
};

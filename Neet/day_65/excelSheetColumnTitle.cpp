#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <string>

class Solution {
    public:
        std::string convertToTitle(int columnNumber) {
            unsigned int base = 26;

            std::map<int, char> numToChar = {
                {0, 'A'}, {1, 'B'}, {2, 'C'}, {3, 'D'}, {4, 'E'},
                {5, 'F'}, {6, 'G'}, {7, 'H'}, {8, 'I'}, {9, 'J'},
                {10, 'K'}, {11, 'L'}, {12, 'M'}, {13, 'N'}, {14, 'O'},
                {15, 'P'}, {16, 'Q'}, {17, 'R'}, {18, 'S'}, {19, 'T'},
                {20, 'U'}, {21, 'V'}, {22, 'W'}, {23, 'X'}, {24, 'Y'},
                {25, 'Z'}
            };

            unsigned int exponent;
            long cumSum = 0;
            for (size_t i=1; i<INFINITY; i++) {
                cumSum += pow(base, i);
                if (columnNumber <= cumSum) {
                    exponent = i-1;
                    break;
                }
            }
            std::printf("exponent is %d\n", exponent);

            // adjust base
            columnNumber --;

            // subtract offset
            for (size_t i=1; i<=exponent; i++) {
                columnNumber -= pow(base, i);
            }

            std::string res = "";
            for (int i=exponent; i>=0; i--) {
                int key = (int)(columnNumber / pow(base, i));
                res.push_back(numToChar[key]);
                columnNumber -= key*pow(base, i);
            }

            std::printf("%s\n", res.c_str());
            return res;
        }
};

int main() 
{
    Solution solution = Solution();
    const int columnNumber = 701;
    solution.convertToTitle(columnNumber);
}
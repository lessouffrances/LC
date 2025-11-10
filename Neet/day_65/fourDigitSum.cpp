#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <string>
#include <numeric>
#include <vector>

class Solution {
    public:
    int fourDigitSum(int S) 
    {
        std::vector<unsigned int> code = {0, 0, 0, 0};

        // 1-prefixes
        std::vector<std::vector<unsigned int>> onePrefixes;
        std::printf("1-prefixes are filled: \n");
        for (size_t i=0; i<=9; i++) {
            code[0] = i;
            std::printf("%d, %d, %d, %d\n", code[0], code[1], code[2], code[3]);
            onePrefixes.push_back({code[0], code[1], code[2], code[3]});
        }
        std::printf("There are %zu 1-prefixes in total.\n\n", onePrefixes.size());

        // 2-prefixes
        std::vector<std::vector<unsigned int>> twoPrefixes;
        std::printf("2-prefixes are filled: \n");
        // for each 1-prefix option, fill the second digit
        for (size_t i=0; i<onePrefixes.size(); i++) {
            for (size_t j=0; j<=9; j++) {
                std::vector<unsigned int> twoPrefix = onePrefixes[i];
                twoPrefix[1] = j;
                std::printf("%d, %d, %d, %d\n", twoPrefix[0], twoPrefix[1], twoPrefix[2], twoPrefix[3]);
                twoPrefixes.push_back(twoPrefix);
            }
            std::printf("\n");
        }
        std::printf("There are %zu 2-prefixes in total.\n\n", twoPrefixes.size());

        // 3-prefixes
        std::vector<std::vector<unsigned int>> threePrefixes;
        std::printf("3-prefixes are filled: \n");
        // for each 2-prefix option, fill the thrid digit
        for (size_t i=0; i<twoPrefixes.size(); i++) {
            for (size_t j=0; j<=9; j++) {
                std::vector<unsigned int> threePrefix = twoPrefixes[i];
                threePrefix[2] = j;
                std::printf("%d, %d, %d, %d\n", threePrefix[0], threePrefix[1], threePrefix[2], threePrefix[3]);
                threePrefixes.push_back(threePrefix);
            }
            std::printf("\n");
        }
        std::printf("There are %zu 3-prefixes in total.\n\n", threePrefixes.size());

        // 4-prefixes
        std::vector<std::vector<unsigned int>> fourPrefixes;
        std::printf("4-prefixes are filled: \n");
        // for each 3-prefix option, fill the fourth digit
        for (size_t i=0; i<threePrefixes.size(); i++) {
            for (size_t j=0; j<=9; j++) {
                std::vector<unsigned int> fourPrefix = threePrefixes[i];
                fourPrefix[3] = j;
                std::printf("%d, %d, %d, %d\n", fourPrefix[0], fourPrefix[1], fourPrefix[2], fourPrefix[3]);
                fourPrefixes.push_back(fourPrefix);
            }
            std::printf("\n");
        }
        std::printf("There are %zu 4-prefixes in total.\n\n", fourPrefixes.size());
        
        unsigned int res = 0;
        for (const std::vector<unsigned int> fourPrefix : fourPrefixes) {
            unsigned int sum = std::accumulate(fourPrefix.begin(), fourPrefix.end(), 0u);
            if (sum == S) {
                res += 1;
            }
        }

        return res;
    }
};

int main()
{
    Solution solution = Solution();

    struct TestObject {
        int S;
        int res;
    };

    std::vector<TestObject> testCases = {
        { 35, 4 }, // happy path
        { 0, 1 } , // edge case 1
        { 36, 1 } , // edge case 2
        { 4, 35 }
    };
    
    bool failed = false;
    for (size_t i=0; i<testCases.size(); i++) {
        if (solution.fourDigitSum(testCases[i].S) != testCases[i].res) {
            failed = true;
            std::printf("The %zu th test case failed.\n", i+1);
            std::printf("The expected is %0u but actual is %0u\n", testCases[i].S, testCases[i].res);
        }
    }

    if (!failed) {
        std::printf("All %zu test cases have been successfully passed.\n", testCases.size());
    }
    return 0;
} 


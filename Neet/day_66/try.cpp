#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string S) {
    if (S.find('C') == string::npos) {
        return -1;
    }

    if (S.size() < 1 || S.size() > 100) {
        return -1;
    }

    std::vector<char> boardVec(S.begin(), S.end());
    int res = 0;
    for (size_t i=0; i<boardVec.size(); i++) {
        if (i < 3 || boardVec[i] != 'C') {
            continue;
        }

        for (int j=i; j>=0; j-=3) {
            if (boardVec[j] == 'T') {
                boardVec[j] = '.';
                boardVec[i] = 'T';
                res += 1;
                break;
            }

        }
    }
    return res;
}

int main() 
{
    struct TestObject {
        std::string board;
        int expectedRes;
        std::string desc;
    };

    std::vector<TestObject> testSuite = {
        { "TTTCCCCCC", 6, "Example 1: Multiple tokens and coins" },
        { "T.C.C.C", 0, "Example 2: Token can reach some coins" },
        { "T..C..C", 2, "Example 3: Token jumps to reachable coins" },
        { "C...T", 0, "Example 4: Coin before token, unreachable" },
        { ".T.C..", 0, "Example 5: Token can't reach coin" },
        { "TT.CCC", 2, "Example 6: Multiple tokens, some coins unreachable" },
        { "T", 0, "Edge: Single token, no coins" },
        { "C", 0, "Edge: Single coin, no tokens" },
        { ".", 0, "Edge: Single empty position" },
        { "", 0, "Edge: Empty board" },
        { "TC", 0, "Edge: Token and coin adjacent" },
        { "T..C", 1, "Token exactly 3 positions from coin" },
        { "TCCCCCC", 2, "Token with many consecutive coins" },
        { "...T...C", 0, "Token and coin with spacing" }
    };    

    int passed = 0;
    int failed = 0;

    for (size_t i=0; i<testSuite.size(); i++) {
        TestObject currentTestCase = testSuite[i];

        if (solution(currentTestCase.board) != currentTestCase.expectedRes) {
            failed += 1;
            std::printf("The %zu th test case failed.\n", i+1);
            std::printf("The failed test case is %s\n", currentTestCase.board.c_str());
        } else {
            passed += 1;
        }
    }
    std::printf("Passed: %d v.s. Failed %d\n", passed, failed);
}


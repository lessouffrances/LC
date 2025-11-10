#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <string>
#include <numeric>

class Solution {
    public:
    int tokenScore(std::vector<int> &points, std::string &tokens)
    {
        // question bug
        if ((points.size() != tokens.size()) || (points.size() == 0) || (tokens.size() == 0)) {
            return 0;
        }
        
        int baseScore = 0;

        for (size_t i=0; i<points.size(); i++) {
            if (tokens[i] == 'T') {
                baseScore += points[i];
            }
        }
        std::printf("Now the base score is %d\n", baseScore);

        int bonusScore = 0;
        for (size_t i=0; i<tokens.size()-1; i++) {
            if (tokens[i] == 'T' && tokens[i+1] == 'T') {
                bonusScore += 1;
            }
        }
        std::printf("Now the bonus score is %d\n", bonusScore);

        std::printf("Total score is %d\n", baseScore+bonusScore);
        return baseScore+bonusScore;
    }
};

int main()
{
    Solution solution = Solution();

    struct TestObject final {
        std::vector<int> points;
        int baseScore;
        int bonusScore;
        int totalScore;
        std::string tokens;
    };

    std::vector<TestObject> testCases = {
        { {3, 4, 5, 2, 3}, 8, 1, 9, "TEETT" }, 
        { {3, 2, 1, 2, 2}, 5, 2, 7, "ETTTE" }, 
        { {2, 2, 2, 2}, 8, 3, 11, "TTTT" },
        { {0, 0, 1, 2, 3}, 2, 1, 3, "TTETE" },
        { {0, 0, 0, 0, 1}, 1, 4, 5, "TTTTT" },
        { {}, 0, 0, 0, "TTEE"}, // test case issue
    };

    for (size_t i=0; i<testCases.size(); i++) {
        // Current test case
        TestObject test = testCases[i];

        int res = solution.tokenScore(test.points, test.tokens);
        if (res != test.totalScore) {
            std::printf("The %zu-th test case failed.\n", i+1);
            std::printf("The failing points are: [");
            for (size_t j=0; j<test.points.size(); j++) {
                std::printf("%d", test.points[j]);
                if (j < test.points.size()-1) std::printf(", ");
            }
            std::printf("]\n");
            std::printf("The failing tokens are: %s\n", test.tokens.c_str());
        }
    }
    std::printf("%zu test cases are successfully passed.", testCases.size());


    // separate test cases
    // std::vector<int> points = {3, 4, 5, 2, 3};
    // const int baseScore = 8;
    // const int bonusScore = 1;
    // std::string tokens = "TEETT";

    // std::vector<int> points = {3, 2, 1, 2, 2};
    // const int baseScore = 5;
    // const int bonusScore = 2;
    // std::string tokens = "ETTTE";

    // std::vector<int> points = {2, 2, 2, 2};
    // const int baseScore = 8;
    // const int bonusScore = 3;
    // std::string tokens = "TTTT";

    // std::vector<int> points = {0, 0, 1, 2, 3};
    // const int baseScore = 2;
    // const int bonusScore = 1;
    // std::string tokens = "TTETE";

    // std::vector<int> points = {0, 0, 0, 0, 1};
    // const int baseScore = 1;
    // const int bonusScore = 4;
    // std::string tokens = "TTTTT";

    return 0;
} 


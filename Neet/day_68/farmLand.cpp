#include <vector>
#include <algorithm>
#include <cstdio>


using namespace std;

class Solution {
    public:
    int maxGoodSquare(vector<vector<int>>& land) 
    {
        // allocate dp
        vector<vector<int>> dp(land.size(), vector<int>(land[0].size(), 0));

        printf("The dp is: \n\n");
        for (size_t r=0; r<dp.size(); r++) {
            for (size_t c=0; c<dp[0].size(); c++) {
                printf("%d ", dp[r][c]);
            }
            printf("\n");
        }
        printf("\n\n");

        // bottom-up traversal
        for (int r=dp.size()-1; r>=0; r--) {
            for (int c=dp[0].size()-1; c>=0; c--) {
                // handling bottom row and right col
                if (r == dp.size()-1 || c == dp[0].size()-1) {
                    dp[r][c] = land[r][c];
                    continue;
                }

                if (land[r][c] == 0) {
                    dp[r][c] = 0;
                } else {
                    if (land[r+1][c] == 1 && land[r][c+1] == 1 && land[r+1][c+1] == 1) {
                        dp[r][c] = dp[r+1][c+1] + 1;
                    } else {
                        dp[r][c] = 1;
                    }
                }
            }
        }

        int longestEdge = 0;
        for (auto& row : dp) {
            longestEdge = max(longestEdge, *max_element(row.begin(), row.end()));
        }

        int maxArea = pow(longestEdge, 2);
        printf("The max good area is %d", maxArea);
        return maxArea;
    }
    
};

int main() 
{
    Solution solution = Solution();

    struct TestObject {
        vector<vector<int>> land;
        int expectedSquareArea;
    };

    vector<TestObject> testSuite = {
        { {{0, 1, 1, 0, 1}, {1, 1, 0, 1, 0}, {0, 1, 1, 1, 0}, {1, 1, 1, 1, 0}, {1, 1, 1, 1, 1}, {0, 0, 0, 0, 0}}, 9 },
        { {{1}}, 1 },
        { {{0}}, 0 },
        { {{1, 1}, {1, 1}}, 4 },
        { {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, 1 },
        { {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}}, 1 },
    };
    
    int passed = 0, failed = 0;
    for (auto& testCase : testSuite) {
        if (solution.maxGoodSquare(testCase.land) != testCase.expectedSquareArea) {
            failed ++;
            printf("The following testCase is failing: \n\n");
            for (size_t r=0; r<testCase.land.size(); r++) {
                for (size_t c=0; c<testCase.land[0].size(); c++) {
                    printf("%d ", testCase.land[r][c]);
                }
                printf("\n");
            }
            printf("\n\n");
        } else {
            passed ++;
        }
    }
    printf("\nPassed : Failed => %d : %d\n", passed, failed);
    return 0;


}
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <string>
#include <numeric>
#include <vector>

class Solution {
    public:
    int stackMoves(const std::vector<int>& A) 
    {
        if (A.size() == 0) {
            return 0;
        }

        int ops = 0;
        std::vector<std::vector<int>> numberClusters = cluster(A);
        for (auto& numberCluster : numberClusters) {
            ops += *std::max_element(numberCluster.begin(), numberCluster.end());
        }
        return ops;
    }

    void printClusters(const std::vector<std::vector<int>>& clusters) {
        std::printf("{ ");
        
        for (size_t i = 0; i < clusters.size(); i++) {
            std::printf("{");
            
            for (size_t j = 0; j < clusters[i].size(); j++) {
                std::printf("%d", clusters[i][j]);
                if (j < clusters[i].size() - 1) {
                    std::printf(", ");
                }
            }
            
            std::printf("}");
            if (i < clusters.size() - 1) {
                std::printf(", ");
            }
        }
        std::printf(" }\n");
    }

    std::vector<std::vector<int>> cluster(const std::vector<int>& A)
    {
        std::vector<std::vector<int>> numberClusters;
        int i = 0, j = 0;
        while (i<A.size() && j<A.size()) {
            if (A[i] == 0) {
                i++;
            } else {
                j = i;
                std::vector<int> currentCluster;
                while (j<A.size() && A[j] != 0) {
                    currentCluster.push_back(A[j]);
                    j++;
                }
                if (!currentCluster.empty()) { numberClusters.push_back(currentCluster); }
                i = j;
            }
        }
        printClusters(numberClusters);
        return numberClusters;
    }
};


int main()
{
    Solution solution = Solution();

    struct TestObject {
        std::vector<int> A;
        std::vector<std::vector<int>> expectedNumberClusters;
        int expectedOps;
    };

    std::vector<TestObject> testSuite = {
        { {1, 0, 1, 2, 2}, { {1}, {1, 2, 2} }, 3 },
        { {0, 1, 0, 1, 0, 1}, { {1}, {1}, {1} }, 3},
        { {1, 1, 1, 1, 0}, { {1, 1, 1, 1} }, 1 }, 
        { {0, 1, 0, 2, 0, 3}, { {1}, {2}, {3} }, 6},
        { {1, 0, 1, 2, 3, 6, 3, 4, 0, 10}, { {1}, {1, 2, 3, 6, 3, 4}, {10}}, 17} 
    };

    int passed = 0, failed = 0;
    for (auto& testCase : testSuite) {
        if (solution.stackMoves(testCase.A) != testCase.expectedOps) {
            failed ++;
            std::printf("The failed test case: [ ");
            for (size_t i=0; i<testCase.A.size(); i++) {
                if (i == testCase.A.size()-1) {
                    std::printf("%d ]\n", testCase.A[i]);
                    break;
                }
                std::printf("%d, ", testCase.A[i]);
            }
        } else {
            passed ++;
        }
    }
    std::printf("Passed %d versus Failed %d\n", passed, failed);
}
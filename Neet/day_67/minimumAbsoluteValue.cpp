#include <vector>
#include <cstdio>
#include <cmath>
#include <climits>

class Solution {
    public:
    int minimumAbsoluteValue(const std::vector<int>& A)
    {
        if (A.size() < 1) {
            return 0;
        }

        long long totalSum = 0;
        for (int number : A) {
            totalSum += number;
        }

        std::vector<long long> candidates;
        candidates.push_back(totalSum);

        // iterate through A and compute each option 
        for (auto& number : A) {
            long long sumOfRest = totalSum-number;
            long long candidate = sumOfRest-number;
            candidates.push_back(candidate);
        }
        // printVecOfInt(candidates);

        long long minAbsValue = LLONG_MAX;
        for (auto& candidate : candidates) {
            long long currAbsValue = std::abs(candidate-0);
            if (currAbsValue < minAbsValue) {
                minAbsValue = currAbsValue;
            }
        }

        // std::printf("%lld", minAbsValue);
        return static_cast<int>(minAbsValue);
    }

    private: 
    void printVecOfInt(const std::vector<long long>& A) 
    {
        std::printf("[");
        for (size_t i=0; i<A.size(); i++) {
            std::printf("%lld", A[i]);
            std::printf(", ");
        }
        std::printf("]\n");
    }

};

int main() 
{
    Solution solution = Solution();

    struct TestObject {
        std::vector<int> A;
        std::vector<int> expectedCandidates;
        int expectedMinAbsValue;
    };

    std::vector<TestObject> testSuite = {
        // Test 1: Example from problem - [1, 3, 2, 5]
        { {1, 3, 2, 5}, {11, 9, 5, 7, 1}, 1 },
        
        // Test 2: Example from problem - [-4, 0, -3, -3]
        { {-4, 0, -3, -3}, {-10, -2, -10, -4, -4}, 2 },
        
        // Test 3: Example from problem - [4, -3, 5, -7]
        { {4, -3, 5, -7}, {-1, -9, 5, -11, 13}, 1 },
        
        // Test 4: Example from problem - [-15, 18, -1, -1, 10, -22]
        { {-15, 18, -1, -1, 10, -22}, {-11, 19, -47, -9, -9, -31, 33}, 9 },
        
        // Test 5: Single element positive
        { {5}, {5, -5}, 5 },
        
        // Test 6: Single element negative
        { {-5}, {-5, 5}, 5 },
        
        // Test 7: Single element zero
        { {0}, {0, 0}, 0 },
        
        // Test 8: Two elements that cancel out
        { {5, -5}, {0, -10, 10}, 0 },
        
        // Test 9: All positive numbers
        { {1, 2, 3, 4}, {10, 8, 6, 4, 2}, 2 },
        
        // Test 10: All negative numbers
        { {-1, -2, -3, -4}, {-10, -8, -6, -4, -2}, 2 },
        
        // Test 11: All zeros
        { {0, 0, 0}, {0, 0, 0, 0}, 0 },
        
        // Test 12: Sum already zero
        { {1, 2, -3}, {0, -2, -4, 6}, 0 },
        
        // Test 13: Large positive sum
        { {100, 50, 30}, {180, -20, 80, 120}, 20 },
        
        // Test 14: Large negative sum
        { {-100, -50, -30}, {-180, 20, -80, -120}, 20 },
        
        // Test 15: Mixed with optimal flip
        { {10, -3, -2, -4}, {1, -19, 7, 5, 9}, 1 },
        
        // Test 16: Two elements, both positive
        { {3, 5}, {8, 2, -2}, 2 },
        
        // Test 17: Two elements, both negative
        { {-3, -5}, {-8, -2, 2}, 2 },
        
        // Test 18: One large, many small
        { {100, 1, 1, 1, 1}, {104, -96, 102, 102, 102, 102}, 96 },
        
        // Test 19: Perfect balance possible
        { {7, 3, -5}, {5, -9, -1, 15}, 1 },
        
        // Test 20: Zero in array
        { {0, 5, -3}, {2, 2, -8, 8}, 2 },
        
        // Test 21: Many elements with small differences
        { {1, 1, 1, 1, -2}, {2, 0, 0, 0, 0, 6}, 0 },
        
        // Test 22: Flipping doesn't help (odd sum)
        { {1, 1, 1}, {3, 1, 1, 1}, 1 },
        
        // Test 23: Large array with balance
        { {5, -2, 3, -8, 1, 4, -3, 2}, {2, -8, 6, -4, 18, 0, -6, 8, -2}, 0 },
        
        // Test 24: Extreme values
        { {1000, -999}, {1, -1999, 1999}, 1 },
        
        // Test 25: Multiple same values
        { {5, 5, 5, 5, -18}, {2, -8, -8, -8, -8, 38}, 2 },
        
        // Test 26: Two identical positive elements
        { {7, 7}, {14, 0, 0}, 0 },
        
        // Test 27: Two identical negative elements
        { {-7, -7}, {-14, 0, 0}, 0 },
        
        // Test 28: Three elements forming zero
        { {5, -2, -3}, {0, -10, 4, 6}, 0 },
        
        // Test 29: Alternating signs
        { {1, -1, 2, -2, 3}, {3, 1, 5, -1, 7, -3}, 1 },
        
        // Test 30: Large array all same positive
        { {3, 3, 3, 3, 3}, {15, 9, 9, 9, 9, 9}, 9 }
    };

    int passed = 0, failed = 0;
    for (auto& testCase : testSuite) {
        if (solution.minimumAbsoluteValue(testCase.A) != testCase.expectedMinAbsValue) {
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
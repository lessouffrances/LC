#include <vector>
#include <cstdio>
#include <algorithm>

class Solution {
    public:
    int maximumNumberFromThreeDigits(const std::vector<int>& A) 
    {
        int res = 0;
        if (A.size() == 1) {
            res = A[0];
            return res;
        } 
        if (A.size() == 2) {
            if (A[0] == 0) {
                res = A[1];
                return res;
            } else {
                res = A[0]*10+A[1];
                return res;
            }
        }

        std::vector<int> candidates;
        
        int maxNumber = 0;
        for (size_t i=0; i<A.size(); i++) {
            candidates.push_back( A[i]);
        }

        for (size_t i=0; i<A.size(); i++) {
            if (A[i] == 0) continue;
            for (size_t j=i+1; j<A.size(); j++) {
                candidates.push_back(A[i]*10+A[j]);

            }
        }

        for (size_t i=0; i<A.size(); i++) {
            if (A[i] == 0) continue;
            for (size_t j=i+1; j<A.size(); j++) {
                for (size_t k=j+1; k<A.size(); k++) {
                    candidates.push_back(A[i]*100+A[j]*10+A[k]);
                }
            }
        }

        if (!candidates.empty()) {
            res = *std::max_element(candidates.begin(), candidates.end());
        }
        std::printf("%d\n", res);
        return res;
    };

};

int main() 
{
    Solution solution = Solution();
    struct TestObject {
        std::vector<int> A;
        int expectedRes;
    };

    std::vector<TestObject> testSuite = {
        { {7, 2, 3, 3, 4, 9}, 749 },
        { {0, 0, 5, 7}, 57 }, 

        { {0}, 0 },
        { {9}, 9 },

        { {0, 0}, 0 },
        { {0, 1}, 1 },
        { {0, 9}, 9 },
        { {1, 0}, 10 },
        { {9, 0}, 90 },
        { {9, 9}, 99 },

        { {0, 0, 1}, 1},
        { {0, 9, 9}, 99 },
        { {9, 0, 9}, 909 },
        { {9, 9, 0}, 990 },

        { {0, 9, 0, 9}, 909 },
        { {0, 0, 9, 9}, 99 },
        { {9, 0, 0, 9}, 909 },
        { {9, 1, 0, 9}, 919 },
        { {9, 0, 1, 9}, 919 },
        { {0, 9, 0, 0, 0}, 900},
        { {9, 0, 0, 0, 9}, 909},

        { {9, 9, 9, 9, 9, 9}, 999},
        { {0, 0, 0, 0, 0, 0}, 0},
        { {9, 0, 0, 0, 0, 0}, 900},
        { {0, 9, 0, 0, 1, 0}, 910},
        
        { {1, 2, 3, 4, 5}, 345},
        { {5, 4, 3, 2, 1}, 543},
        { {5, 4, 5, 4, 5}, 555},
        { {4, 5, 4, 5, 4}, 554},
    };

    int passed = 0, failed = 0;
    for (auto& testCase : testSuite) {
        if (solution.maximumNumberFromThreeDigits(testCase.A) != testCase.expectedRes) {
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
#include <vector>
#include <cstdio>
#include <algorithm>

class Solution {
    struct TwoHalves {
        std::vector<int> left;
        std::vector<int> right;
    };

    public:
    int splitJoin(std::vector<int>& A) 
    {
        if (A.size() <= 1) {
            return 0;
        }

        int res = 0;
        // decompose logics into separate func
        std::vector<TwoHalves> splitWays = splitArray(A);

        // sort and join
        std::vector<int> sortedJoinedArray;
        for (auto& currentSplit : splitWays) {

            std::sort(currentSplit.left.begin(), currentSplit.left.end());
            std::sort(currentSplit.right.begin(), currentSplit.right.end());
            sortedJoinedArray = currentSplit.left;
            sortedJoinedArray.insert(sortedJoinedArray.end(), currentSplit.right.begin(), currentSplit.right.end());            

            if (checkForNonDescendingOrder(sortedJoinedArray)) {
                res += 1;
            }
        }
        return res;
    }

    // can private functions be tested?
    private:
    std::vector<TwoHalves> splitArray(std::vector<int>& A) 
    {   
        std::vector<TwoHalves> res;
        for (size_t i=1; i<A.size(); i++) {
            TwoHalves split;
            std::vector<int> l(A.begin(), A.begin()+i);
            std::vector<int> r(A.begin()+i, A.end());

            res.push_back({l, r});
        }
        return res;
    }

    bool checkForNonDescendingOrder(std::vector<int>& A)
    {
        for (size_t i=0; i<A.size()-1; i++) {
            if (A[i+1] < A[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() 
{
    Solution solution = Solution();
    struct TestObject {
        std::vector<int> array;
        // std::vector<TwoHalves> splitWays;
        // int numOfSplitWays;
        int res;
    };

    std::vector<TestObject> testSuite = {
        { {}, 0 },
        { {5}, 0 }, 
        { {1, 2}, 1 }, 
        { {2, 1}, 0 }, 
        { {1, 3, 2, 4}, 2 }, 
        { {1, 2, 3}, 2 }, 
        { {1, 2, 3, 4}, 3 }, 
        { {1, 2, 3, 4, 5}, 4 }, 
        { {1, 2, 3, 4, 5, 6 }, 5 },
        { {3, 2, 1}, 0 },
        { {4, 3, 2, 1}, 0 },
        { {5, 4, 3, 2, 1}, 0 }, 
        { {3, 3, 3}, 2 },
        { {5, 5, 5, 5}, 3 },
        { {7, 7, 7, 7, 7}, 4 },
        { {1, 2, 2, 3}, 3 },
        { {2, 1, 2, 1}, 0 },
        { {1, 1, 2, 2, 3, 3}, 5 }, 
        { {2, 1, 3}, 1 },
        { {1, 3, 2}, 1}, 
        { {3, 1, 2}, 0 },
        { {1, 2, 4, 3, 5}, 3 },
        { { -1, 2, 0, 3 }, 2 },
        { {-5, -3, -1}, 2 }, 
        { {-1, -5, -3}, 0 },
        { {-2, -1, 0, 1, 2}, 4 },
        { {0, 1, 0, 2}, 2 },
        { {0, 0, 0, 0}, 3 },
        { {1, 3, 2, 4, 3, 5}, 3 },
        { {-999999, 999999, 1000000, -1000000 }, 0}
    };

    bool failed = false;
    for (auto& test : testSuite) {
        std::vector<int> array = test.array;
        int expected = test.res;

        if (solution.splitJoin(array) != expected) {
            failed = true;
            std::printf("The failed test case: [ ");
            for (size_t i=0; i<array.size(); i++) {
                if (i == array.size()-1) {
                    std::printf("%d ]\n", array[i]);
                    break;
                }
                std::printf("%d, ", array[i]);
            }
        }
        
    }

    if (!failed) {
        std::printf("All %zu test cases have been successfully passed!\n", testSuite
    .size());
    }
}

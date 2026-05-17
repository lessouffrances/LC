// For 2 arrays a and b of equal length, 
// the array correlation is defined as 
// the sum of all values b[i] where b[i] is greater than a[i].

// Given two integer arrays a and b of the same length, 
// rearrange the elements of array b to maximize the array correlation.
// Return the maximum possible array correlation value.

// Note: You are not allowed to rearrange the elements in array a.

// Example:
// n = 5,
// a = [1, 2, 3, 4, 5]
// b = [3, 5, 4, 6, 2]
// output = 20
// b can be rearranged to [2, 3, 4, 5, 6].
// Now for each index, the integers in b are greater than those in a.
// The array correlation is 2 + 3 + 4 + 5 + 6 = 20.

// n = 5,
// a = [1, 4, 2, 1, 3] => [1, 1, 2, 3, 4]
// b = [2, 1, 3, 2, 2] => [1, 2, 2, 2, 3]
// output = 7

// Function Description:
// Complete the function getMaxArrayCorrelation with following parameters:
// a[n]: the fixed order array
// b[n]: the array to reorder

// Return:
// long int: the maximum possible array correlation

class Solution
{
    public:
    long long getMaxArrayCorrelation(vector<int>& a, vector<int>& b) {
        vector<int> sortedA = a;
        sort(sortedA.begin(), sortedA.end());
        sort(b.begin(), b.end());

        long long res = 0;
        int j = 0;
        for (int i = 0; i < b.size(); i++) {
            if (j < sortedA.size() && b[i] > sortedA[j]) {
                res += b[i];
                j++;
            }
        }
        return res;
    }
};

// a = [1, 4, 2, 1, 3] => [1, 1, 2, 3, 4]
// b = [2, 1, 3, 2, 2] => [1, 2, 2, 2, 3]

//        j
// [1, 1, 2, 3, 4]
//              i
// [1, 2, 2, 2, 3]

// res = 2+2+3 = 7
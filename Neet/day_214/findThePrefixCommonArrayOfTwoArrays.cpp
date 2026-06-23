//            i
// A = [1,3,2,4]
// B = [3,1,2,4]

// C = [0,2,3,4]
class Solution 
{
    public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n = A.size();
        vector<int> counterA(n+1, 0);
        vector<int> counterB(n+1, 0);
        vector<int> res;

        for (int i=0; i<n; i++) {
            counterA[A[i]]++;
            counterB[B[i]]++;

            int currCommon = 0;
            for (int j = 1; j <= n; j++) {
                currCommon += min(counterA[j], counterB[j]);
            }
            res.push_back(currCommon);
        }
        return res;
    }
};
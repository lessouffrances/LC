// Let's design a critical component for a Test Automation Framework. 
// Our framework needs to verify the behavior of a system (like an e-commerce site) that has data changing over time. For example, 
// to validate a customer's invoice from last week, 
// our Test Agent must be able to query what the exact price of 
// a product was at the moment of purchase.
// To do this, the agent is given access to a 'Source of Truth' (SoT). 
// The SoT is a list of records sorted chronologically 
// by timestamp.

/*
Each record contains information (e.g., price) that is valid from its timestamp up to the timestamp of the next record.
Your task is to write a function that takes a sorted list of input timestamps (representing the times to be queried) 
and efficiently returns the correct record for each one.

Assumptions:
The SoT is a list of (timestamp, value) tuples, sorted by timestamp.
The queries list (for the core problem) is also sorted by timestamp.

Step 1:
     confirm the understanding of the question
Step 2:
     discuss input/output
SoT = [(3,4), (7，5)，(8,2),(10,5),(15,7),(20,4)]
queries = [2,4,6,7,10,15,19,25,27]
result = [None,4,4,5,5,7,7,4,4]

example: ts: 2 => none, 
         ts: 4 => 4
                
condition? 
lower_bound: is smaller or equal to the queried ts
*/

struct SoT
{
    int timestamp;
    int value;
    SoT(int ts, int val) : timestamp(ts), value(val) {}
};

class BinarSearchSolution
{
    public:
    vector<int> getQueriedPrices(vector<SoT>& sourceOfTruth, vector<int>& timestamps)
    {
        if (sourceOfTruth.empty()) return vector<int>(timestamps.size(), -1);
        if (timestamps.empty()) return {};

        int n = timestamps.size();
        // loop thru the queried ts
        vector<int> res;
        for (int i=0; i<n; i++) {
            int queriesTS = timestamps[i];
            res.push_back(getPriceOfSingleTimestamp(sourceOfTruth, queriedTimestamp));
        }
        return res;
    }

    private:
    int getPriceOfSingleTimestamp(vector<SoT>& sourceOfTruth, int timestamp)
    {
        if (sourceOfTruth.empty()) return -1;

        int n = sourceOfTruth.size();
        int left = 0, right = n-1;

        int res = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;

            if (sourceOfTruth[mid].timestamp <= timestamp) {
                res = sourceOfTruth[mid].value;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }
};



class TwoPointerSolution
{
    public:
    vector<int> getQueriedPrices(vector<SoT>& sourceOfTruth, vector<int>& timestamps)
    {

    }
};


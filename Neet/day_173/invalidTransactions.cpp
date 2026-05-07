// T: O(N^2)
// S: O(N)

class Solution 
{
    public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        if (transactions.empty()) return {};
        int n = transactions.size();

        vector<bool> invalid(n, false);
        for (int i=0; i<n; i++) {
            Transaction trans1 = parse(transactions[i]);

            if (trans1.amount > 1000) {
                invalid[i] = true;
                continue;
            }

            for (int j=0; j<n; j++) {
                if (i == j) continue;
                Transaction trans2 = parse(transactions[j]);

                if (trans1.name == trans2.name && trans1.city != trans2.city 
                    && abs(trans1.time-trans2.time) <= 60) {
                        invalid[i] = true;
                        invalid[i] = true;
                    }
            }
        }

        // populate the res
        vector<string> res;
        for (int i=0; i<n; i++) {
            if (invalid[i] == true) {
                res.push_back(transactions[i]);
            }
        }
        return res;
    }
    private:
    // alice,20,800,mtv
    // name, time, amount, and city of the transaction.
    struct Transaction
    {
        string name;
        int time;
        int amount;
        string city;
    };

    Transaction parse(const string& info) 
    {
        stringstream ss(info);
        Transaction res;
        string token;
        getline(ss, res.name, ',');
        getline(ss, token, ',');
        res.time = stoi(token);
        getline(ss, token, ',');
        res.amount = stoi(token);
        getline(ss, res.city, ',');
        return res;
    }
};
class Bank 
{
    public:
    Bank(vector<long long>& balance) 
    {
        bal = balance;
        n = bal.size(); // total number of accounts
    }
    
    bool transfer(int account1, int account2, long long money) 
    {
        int acct1 = account1-1;
        int acct2 = account2-1;
        if (acct1 < 0 || acct2 < 0 || acct1 >= n || acct2 >= n) return false;
        if (bal[acct1] < money) return false;

        bal[acct1] -= money;
        bal[acct2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) 
    {
       int acct = account-1;
       if (acct < 0 || acct >= n) return false;

       bal[acct] += money;
       return true;
    }
    
    bool withdraw(int account, long long money) 
    {
        int acct = account-1;
        if (acct < 0 || acct >= n) return false;
        if (bal[acct] < money) return false;

        bal[acct] -= money;
        return true;
    }

    private:
    vector<long long> bal;
    int n;
};
    
    
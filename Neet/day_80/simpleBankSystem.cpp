class Bank {
    private:
    vector<long long>& balance;

    public:
    Bank(vector<long long>& balance) 
    {
        balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money)
    {
        if (balance[account1] >= money) {
            balance[account1] -= money;
            balance[account2] += money;
            return true;
        } 
        return false;
    }
    
    bool deposit(int account, long long money) 
    {
        balance[account] += money;
    }
    
    bool withdraw(int account, long long money) 
    {
        if (money <= balance[account]) {
            balance[account] -= money;
            return true;
        }
        return false;
    }
};
    
    /**
     * Your Bank object will be instantiated and called as such:
     * Bank* obj = new Bank(balance);
     * bool param_1 = obj->transfer(account1,account2,money);
     * bool param_2 = obj->deposit(account,money);
     * bool param_3 = obj->withdraw(account,money);
     */
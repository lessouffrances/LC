class TicTacToe 
{
    public:
    TicTacToe(int n) 
    {
        this->n = n;
        rows(2, vector<int>(n, 0));
        cols(2, vector<int>(n, 0));
        diag(2, 0);
        antiDiag(2, 0);
    }
    
    int move(int row, int col, int player) 
    {
        int p = player-1;
        rows[p][row]++;
        cols[p][col]++;

        if (row == col) diag[p]++;
        if (row+col == n-1) antiDiag[p]++;
        if (rows[p][row] == n || cols[p][col] == n 
            || diag[p] == n || antiDiag[p] == n) return player;
        return 0;
    }

    private:
    int n;
    vector<vector<int>> rows;
    vector<vector<int>> cols;
    vector<int> diag, antiDiag;
};
    
   


// Time: O(1)
// Space: O(N)

class TicTacToe 
{
    public:
    TicTacToe(int n) : n(n),
    rows(2, vector<int>(n, 0)),
    cols(2, vector<int>(n, 0)),
    diag(2, 0),
    antiDiag(2, 0) {}
   
    int move(int row, int col, int player) 
    {
        // convert to 0-based index
        int p = player-1;

        // increment the counter for this player's row and col
        rows[p][row]++;
        cols[p][col]++;

        // if this location is on one of the diag
        if (row == col) diag[p]++;
        if (row + col == n - 1) antiDiag[p]++;

        // do a check
        if (rows[p][row] == n || cols[p][col] == n 
            || diag[p] == n || antiDiag[p] == n) return player;

        return 0;
    }
    private:
    int n;
    vector<vector<int>> rows, cols;
    vector<int> diag, antiDiag;
};
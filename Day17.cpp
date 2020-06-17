// Question -   Surrounded Regions


/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.


*/

// Solution
class Solution {
public:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    int valid(int i, int j, int m, int n)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(vector<vector<char>> &board, int i, int j, int m, int n)
    {
        if(board[i][j] == 'O')
        {
            board[i][j] = 'Y';
            int p_i, p_j;
            for(int l = 0; l < 4; l++)
            {
                p_i = i + di[l];
                p_j = j + dj[l];
                if(valid(p_i, p_j, m, n) && board[p_i][p_j] == 'O')
                    dfs(board, p_i, p_j, m, n);
            }
        }
    }
    void solve(vector<vector<char>>& board)
    {
        int i, j, m, n;
        m = board.size();
        if(m < 2)
        return;
        n = board[0].size();
        for(i = 0; i < m; i++)
        {
            if(board[i][0] == 'O')
            dfs(board, i, 0, m, n);
            if(board[i][n-1] == 'O')
            dfs(board, i, n-1, m, n);
        }
        for(i = 0; i < n; i++)
        {
            if(board[0][i] == 'O')
            dfs(board, 0, i, m, n);
            if(board[m-1][i] == 'O')
            dfs(board, m-1, i, m, n);
        }
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(board[i][j] == 'O')
                board[i][j] = 'X';
                else if(board[i][j] == 'Y')
                board[i][j] = 'O';
            }
        }
    }
};

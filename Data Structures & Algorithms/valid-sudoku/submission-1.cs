public class Solution 
{
    public bool IsValidSudoku(char[][] board) 
    {
        Dictionary<int, HashSet<char>> cols = new Dictionary<int, HashSet<char>>(); 
        Dictionary<int, HashSet<char>> rows = new Dictionary<int, HashSet<char>>();
        Dictionary<string, HashSet<char>> squares = new Dictionary<string, HashSet<char>>();

        for (int row = 0; row < 9; row++) // each row
        {
            for (int col = 0; col < 9; col++) // each col
            {
                if (board[row][col] == '.') // if we are at an empty space
                {
                    continue; // continue
                }

                string square = row / 3 + "," + (col / 3);

                char c = board[row][col];
                if (rows.ContainsKey(row) && rows[row].Contains(c) || cols.ContainsKey(col) && cols[col].Contains(c) || squares.ContainsKey(square) && squares[square].Contains(c))
                {
                    return false;
                }

                if (!rows.ContainsKey(row))
                {
                    rows[row] = new HashSet<char>(); 
                }

                if (!cols.ContainsKey(col))
                {
                    cols[col] = new HashSet<char>();
                }

                if (!squares.ContainsKey(square))
                {
                    squares[square] = new HashSet<char>();
                }

                rows[row].Add(c);
                cols[col].Add(c);
                squares[square].Add(c);
            }
        }

        return true;
    }
}

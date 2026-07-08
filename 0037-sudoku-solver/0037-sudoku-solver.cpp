class Solution {
public:
    bool issafe(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[row][i]==c) return false;

            if(board[i][col]==c) return false;
            
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(issafe(board,row,col,ch)){
                            board[row][col]=ch;

                            if(solve(board)) return true;

                            board[row][col]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
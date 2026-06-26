class Solution {
public:
    vector<vector<string>> ans; 

    void solve(int row,vector<string>&board,vector<int>&leftrow,vector<int>&leftdia,vector<int>&rightdia,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(leftrow[col]==0 && leftdia[col+row]==0 && rightdia[n-1+col-row]==0){
                board[row][col]='Q';

                leftrow[col]=1;
                leftdia[col+row]=1;
                rightdia[n-1+col-row]=1;

                solve(row+1,board,leftrow,leftdia,rightdia,n);

                board[row][col]='.';
                leftrow[col]=0;
                leftdia[col+row]=0;
                rightdia[n-1+col-row]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));

        vector<int>leftrow(n,0);
        vector<int>leftdia(2*n-1,0);
        vector<int>rightdia(2*n-1,0);

        solve(0,board,leftrow,leftdia,rightdia,n);

        return ans;
    }
};
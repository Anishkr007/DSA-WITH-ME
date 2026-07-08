class Solution {
public:
void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&left,vector<int>&upper,vector<int>&lower,int n){

        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(left[row]==0 && upper[col+row]==0 && lower[n-1+col-row]==0){
                board[row][col]='Q';
                left[row]=1;
                upper[row+col]=1;
                lower[n-1+col-row]=1;

                solve(col+1,board,ans,left,upper,lower,n);
                 board[row][col]='.';
                left[row]=0;
                upper[row+col]=0;
                lower[n-1+col-row]=0;

            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));

        vector<int>left(n,0);
        vector<int>upper(2*n-1,0);
        vector<int>lower(2*n-1,0);

        solve(0,board,ans,left,upper,lower,n);

        return ans;
    }
};
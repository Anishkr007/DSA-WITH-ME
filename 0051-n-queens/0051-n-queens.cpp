class Solution {
public:
    bool issafe(int row,int col,vector<string>&board,int n){
        int r=row;
        int c=col;

        while(r>=0){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
        }
         r=row;
        c=col;

        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }

          r=row;
         c=col;

        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c++;
        }

        return true;
    }

    void solve(int row,vector<string>&board,vector<vector<string>>&ans,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(issafe(row,col,board,n)){
                board[row][col]='Q';
                solve(row+1,board,ans,n);
                board[row][col]='.';
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));

        solve(0,board,ans,n);

        return ans;
    }
};
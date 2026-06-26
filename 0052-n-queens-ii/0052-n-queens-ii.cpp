class Solution {
public:
int count=0;
void solve(int r,vector<string>&board, vector<int>&left, vector<int>&leftdia, vector<int>&rightdia,int n){
    if(r==n){
        count++;
        return;

    }
    for(int c=0;c<n;c++){

        if(left[c]==0 && leftdia[r+c]==0 && rightdia[n-1+c-r]==0){
            board[r][c]='Q';
            left[c]=1;
            leftdia[c+r]=1;
            rightdia[n-1+c-r]=1;

            solve(r+1,board,left,leftdia,rightdia,n);

            board[r][c]='.';
             left[c]=0;
            leftdia[c+r]=0;
            rightdia[n-1+c-r]=0;

        }

    }

}
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));

        vector<int>left(n,0);
        vector<int>leftdia(2*n-1,0);
        vector<int>rightdia(2*n-1,0);

        solve(0,board,left,leftdia,rightdia,n);

        return count;
    }
};
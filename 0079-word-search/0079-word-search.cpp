class Solution {
public:
    bool dfs(int r,int c,vector<vector<char>>& board, string word,int index){
        int n=board.size();
        int m=board[0].size();

        if(index==word.size()) return true;

        if(r<0 || c<0 ||r>=n || c>=m||board[r][c]!=word[index] ){
            return false;
        }

        char ch=board[r][c];
        board[r][c]='$';

        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};

        for(int i=0;i<4;i++){
            int nr=r+delrow[i];
            int nc=c+delcol[i];

            if(dfs(nr,nc,board,word,index+1)){
                return true;
            }
        }

        board[r][c]=ch;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,board,word,0)){
                    return true;
                }
            }
        }

        return false;
    }
};
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int row,int col,int index){
        if(word.size()==index) return true;

        if(row<0 || row >= board.size() || col <0 || col>=board[0].size() || board[row][col]!=word[index]) return false;

        char ch = board[row][col];

        board[row][col]='#';

        bool found=dfs(board,word,row+1,col,index+1)||dfs(board,word,row-1,col,index+1)||dfs(board,word,row,col+1,index+1)||dfs(board,word,row,col-1,index+1);

        board[row][col]=ch;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
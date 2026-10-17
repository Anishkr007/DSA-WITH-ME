class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        grid[r][c]=0;

        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

             if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                grid[nr][nc] == 1){
                dfs(nr,nc,grid);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]){
                dfs(i,0,grid);
            }
            if(grid[i][m-1]){
                dfs(i,m-1,grid);
            }
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1){
                dfs(0,j,grid);

            }
            if(grid[n-1][j]==1){
                dfs(n-1,j,grid);
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }

        return count;
    }
};
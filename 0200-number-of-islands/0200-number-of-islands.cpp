class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};
        grid[r][c]='0';

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]=='1'){
                dfs(nr,nc,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int island=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    island++;
                    dfs(i,j,grid);
                }
            }
        }
        return island;
    }
};
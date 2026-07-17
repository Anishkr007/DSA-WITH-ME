class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();

        int delx[]={0,0,-1,1};
        int dely[]={1,-1,0,0};

        grid[x][y]=0;

        for(int i=0;i<4;i++){
            int nx=x+delx[i];
            int ny=y+dely[i];

            if(nx>=0 && ny>=0 && nx<n && ny < m && grid[nx][ny]==1){
                dfs(nx,ny,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();


        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,0,grid);
            }

            if(grid[i][m-1]==1){
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
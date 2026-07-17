class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};
        grid[x][y]='0';

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx<n && ny<m && nx>= 0 && ny>=0 && grid[nx][ny]=='1'){
                dfs(nx,ny,grid);
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
                    dfs(i,j,grid);
                    island++;
                }
            }
        }
        return island;
    }
};
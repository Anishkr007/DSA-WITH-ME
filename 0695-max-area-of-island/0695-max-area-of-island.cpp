class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>&grid){
         int n=grid.size();
        int m=grid[0].size();

        int area=1;
        grid[r][c]=0;

        int dr[]={0,0,1,-1};
        int dc[]={-1,1,0,0};

        for(int i=0;i<4;i++){

            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1){
                area+=dfs(nr,nc,grid);
            }

        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    ans=max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};
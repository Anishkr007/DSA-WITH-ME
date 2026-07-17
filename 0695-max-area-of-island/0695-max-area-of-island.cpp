class Solution {
public:
    
    int dfs(int x,int y,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        int area=1;
        grid[x][y]=0;
        int dx[]={-1,0,0,1};
         int dy[]={0,1,-1,0};

        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny< m && grid[nx][ny]==1){
                area+=dfs(nx,ny,grid);
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
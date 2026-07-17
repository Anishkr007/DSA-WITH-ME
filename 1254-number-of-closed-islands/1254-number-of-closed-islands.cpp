class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();

        int delrow[]={-1,0,0,1};
        int delcol[]={0,-1,1,0};

        queue<pair<int,int>> q;
        q.push({x,y});

        grid[x][y]=1;

        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int nx=a+delrow[i];
                int ny=b+delcol[i];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0){
                    grid[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                dfs(i,0,grid);
            }
            if(grid[i][m-1]==0){
                dfs(i,m-1,grid);
            }        
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==0){
                dfs(0,j,grid);
            }
            if(grid[n-1][j]==0){
                dfs(n-1,j,grid);
            }
        }
int ans=0;

for(int i=1;i<n-1;i++){
    for(int j=1;j<m-1;j++){
        if(grid[i][j]==0){
            dfs(i,j,grid);
            ans++;
        }
    }

}

return ans;

    }
};
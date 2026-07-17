class Solution {
public:
    bool dfs(int r,int c,vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int n=grid1.size();
        int m=grid2[0].size();

        grid2[r][c]=0;

        int delrow[]={0,1,-1,0};
        int delcol[]={-1,0,0,1};

        bool valid=true;

        if(grid1[r][c]==0){
            valid=false;
        }

        for(int i=0;i<4;i++){
            int nr=r+delrow[i];
            int nc=c+delcol[i];

            if(nr>=0 && nc>=0 && nr< n && nc < m && grid2[nr][nc]==1){
                valid=valid&dfs(nr,nc,grid1,grid2);
            }
        }

        return valid;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    if(dfs(i,j,grid1,grid2))
                    ans++;
                }
            }
        }

        return ans;
    }
};
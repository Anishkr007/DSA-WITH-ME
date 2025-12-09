class Solution {
public:
    void BFS(int r,int c,vector<vector<char>>& grid,vector<vector<int>> & vis){
        int n=grid.size();
        int m=grid[0].size();

        vis[r][c]=1;
        queue<pair<int,int>> q;

        q.push({r,c});

       int dr[4]={1,-1,0,0};
      int  dc[4]={0,0,-1,1};

        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                
                    int nr=row+dr[i];
                    int nc=col+dc[i];


                    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1' ){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                
            }


        }


    }


    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis (n,vector<int>(m,0));

        int count=0;

        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]=='1'&& !vis[r][c]){
                    
                    BFS(r,c,grid,vis);
                    count++;
                }

            }
        }
        return count;
    }
    
};
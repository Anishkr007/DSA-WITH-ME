class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int fresh=0;
        queue<pair<int,int>>q;
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int min=0;

        int dr[]={0,0,-1,1};
        int dc[]={-1,1,0,0};

        while(!q.empty() && fresh>0){
            int sz=q.size();
            min++;

            for(int i=0;i<sz;i++){
                auto [r,c]=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];

                    if(nr>=0 && nc>=0 && nr<n && nc < m && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr,nc});
                    }

                }

                
            }



        }

        return (fresh==0?min:-1);
    }
};
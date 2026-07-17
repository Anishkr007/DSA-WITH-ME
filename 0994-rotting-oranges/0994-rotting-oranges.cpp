class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();

       int fresh=0;

       queue<pair<int,int>>q;

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                fresh++;

            }
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }


       } 

       int min=0;

       int delrow[]={-1,0,0,1};
       int delcol[]={0,-1,1,0};

       while(!q.empty() && fresh>0){
            int size=q.size();

            while(size--){

                int x=q.front().first;
                int y=q.front().second;

                q.pop();

                for(int i=0;i<4;i++){
                    int nx=x+delrow[i];
                    int ny=y+delcol[i];

                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        fresh--;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }



            }
            min++;
       }

       if(fresh>0) return -1;

       return min;
    }
};
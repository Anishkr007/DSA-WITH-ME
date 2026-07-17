class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    
                }
            }
        }

        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};

        while(!q.empty()){
            auto curr=q.front();

            q.pop();
            int r=curr.first.first;
            int c=curr.first.second;
            int d=curr.second;

            dist[r][c]=d;

            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},d+1});
                }
            }
        }
        return dist;
    }
};
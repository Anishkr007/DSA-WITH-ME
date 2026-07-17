class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> height(n, vector<int>(m,-1));

        queue<pair<int,int>> q;

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                {
                    q.push({i,j});
                    height[i][j]=0;
                }
            }
        }

        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();

            for(int k=0;k<4;k++)
            {
                int nx=x+dx[k];
                int ny=y+dy[k];

                if(nx>=0 && ny>=0 &&
                   nx<n && ny<m &&
                   height[nx][ny]==-1)
                {
                    height[nx][ny]=height[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        return height;
    }
};